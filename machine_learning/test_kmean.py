import numpy as np
from numpy.testing import assert_almost_equal, assert_array_equal
from sklearn import datasets
import pytest

from machine_learning.kmean import KMean

def test_kmean():
    kmean = KMean(3)
    np.random.seed(123)
    data = np.random.rand(10, 10)
    centers, clusters = kmean.fit(data)
    expected_centers = np.array(
        [[0.35802895, 0.27465978, 0.37407412, 0.45425565, 0.64606972,
          0.28135829, 0.45469279, 0.93947447, 0.73182257, 0.5573656 ],
         [0.68289148, 0.43603794, 0.42587748, 0.61300191, 0.7809057 ,
          0.25315072, 0.87222352, 0.46424806, 0.33757743, 0.48228724],
         [0.36960757, 0.82957965, 0.5506058 , 0.51511403, 0.49961501,
          0.58214646, 0.3377688 , 0.28107386, 0.39990279, 0.51839955]]
    )
    assert_almost_equal(expected_centers, centers)
    expected_clusters = np.array([1, 2, 2, 0, 0, 2, 1, 2, 2, 2])
    assert_array_equal(expected_clusters, clusters)


@pytest.fixture()
def iris():
    data = datasets.load_iris()
    return data


def test_kmean_cluster_iris_correctly(iris):
    kmean = KMean(3)
    def _map(x):
        if x == 1:
            return 2
        elif x == 2:
            return 1
        else:
            return 0

    np.random.seed(123)
    mapping = np.vectorize(_map)
    centers, clusters = kmean.fit(iris["data"])
    clusters = mapping(clusters)
    result = np.mean(iris["target"] == clusters)
    assert result == 0.8933333333333333


def test_kmean_cluster_iris_using_random_partition_init(iris):
    kmean = KMean(3)

    def _map(x):
        if x == 2:
            return 0
        elif x == 1:
            return 1
        else:
            return 2

    mapping = np.vectorize(_map)
    centers, clusters = kmean.fit(iris["data"], init="random_partition")
    clusters = mapping(clusters)
    result = np.mean(iris["target"] == clusters)
    assert result == 0.8933333333333333


def test_kmean_cluster_iris_using_kmean_plus_plus(iris):
    kmean = KMean(3)

    def _map(x):
        if x == 1:
            return 2
        elif x == 2:
            return 1
        else:
            return 0

    np.random.seed(321)
    mapping = np.vectorize(_map)
    centers, clusters = kmean.fit(iris["data"], init="kmean++")
    clusters = mapping(clusters)
    result = np.mean(iris["target"] == clusters)
    assert result == 0.8933333333333333