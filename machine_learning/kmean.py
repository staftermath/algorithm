import numpy as np
from sklearn.metrics.pairwise import euclidean_distances
from sklearn.preprocessing import normalize


class KMean:

    def __init__(self, k: int, e: float = 0.0001):
        self.k = k
        self.e = e

    def fit(self, data: np.ndarray, init="default") -> (np.ndarray, np.ndarray):

        centers = self._initialize(data, init=init)
        return self._assign(data, centers)

    def _initialize(self, data: np.ndarray, init: str = "default"):
        if init == "default":
            return _initialize_default(data, self.k)
        elif init == "random_partition":
            return _initialize_random_partition(data, self.k)
        elif init == "kmean++":
            return _initialize_kmean_plus_plus(data, self.k)
        else:
            raise ValueError(f"Invald initialization type {init}")

    def _assign(self, data: np.ndarray, centers: np.ndarray):
        delta = np.ones(self.k)
        n, d = data.shape
        allocation = None
        while np.max(delta) > self.e:
            allocation = np.argmin(euclidean_distances(data, centers), axis=1)
            new_centers = np.ones((self.k, d))
            for i in range(self.k):
                if data[allocation == i].shape[0] == 0:
                    new_centers[i] = data[np.random.choice(range(n))]
                else:
                    new_centers[i] = np.mean(data[allocation == i], axis=0)

            delta = np.max(np.abs(new_centers - centers))
            centers = new_centers

        return centers, allocation

    def _kmean_pp_assign(self, data: np.ndarray, centers: np.ndarray):
        delta = np.ones(self.k)
        n, d = data.shape
        allocation = None

        def _map(x):
            return np.random.choice(1, prob=x)

        np.vectorize(_map)

        while np.max(delta) > self.e:
            prob = normalize(np.reciprocal(euclidean_distances(data, centers) + 0.0000001), norm="l1", axis=1, copy=False)
            allocation = np.ones(n)
            for i in range(n):
                allocation[i] = np.random.choice(range(self.k), p=prob[i])

            new_centers = np.ones((self.k, d))
            for i in range(self.k):
                new_centers[i] = np.mean(data[allocation == i], axis=0)

            delta = np.max(np.abs(new_centers - centers))
            centers = new_centers

        return centers, allocation


def _initialize_default(data: np.ndarray, k: int, seed: int=123):
    np.random.seed(seed)
    centers = data[np.random.choice(range(data.shape[0]), k, replace=False)]
    return centers


def _initialize_random_partition(data: np.ndarray, k: int, seed: int=123):
    np.random.seed(seed)
    d = data.shape[1]
    label = np.random.choice(range(k), data.shape[0])
    centers = np.ones((k, d))
    for i in range(k):
        centers[i] = np.mean(data[label == i], axis=0)

    return centers


def _initialize_kmean_plus_plus(data: np.ndarray, k: int, seed: int = 123):
    n, d = data.shape
    centers = np.ones((k, d))
    centers[0] = data[np.random.choice(range(n), 1)][0]
    for i in range(1, k):
        prob = np.min(euclidean_distances(data, centers, squared=True), axis=1)
        prob = prob.flatten() / np.sum(prob)
        center = np.random.choice(range(n), p=prob)
        centers[i] = center

    return centers
