#include <string>
#include <vector>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	string test = argv[1];
	string pattern = argv[2];
	cout << test << endl;
	cout << pattern << endl;
	int p_size = pattern.size();
	int s_size = test.size();
	vector<int> lps(p_size);
	int len = 0, i=1;
	while (i<p_size) {
		if (pattern[i] == pattern[len]){
			len++;
			lps[i] = len;
			i++;
		} else if (len==0) {
			lps[i]=len;
			i++;
		} else {
			len = lps[len-1];
		}
	}
	len=0;
	i=0;
	for (int i=0; i<p_size; i++) {
		cout << lps[i] << "," << flush;
	}
	cout << endl;
	int result = 0;
	while (i<s_size) {
		if (test[i] == pattern[len]) {
			i++;
			len++;
			if (len==p_size) {
				result++;
				len = lps[len-1];
			}
		} else if (len==0){
			i++;
		} else {
			len = lps[len-1];
		}
	}
	// return result;
	cout << "found " << result << endl;
}