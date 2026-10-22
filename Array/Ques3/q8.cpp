#include <iostream>
#include <vector>
#include <string>

using namespace std;

// KMP Algorithm

class KMPAlgorithm {
public:
    // Step 1: Compute the LPS (Longest Prefix which is also Suffix) array
    vector<int> computeLPS(string pat) {
        int m = pat.length();
        vector<int> lps(m, 0);
        
        int len = 0; // Length of the previous longest prefix suffix
        int i = 1;
        
        while (i < m) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    // Fall back to the previous matching prefix length
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    // Step 2: Search for pattern in text using KMP
    vector<int> searchPattern(string pat, string txt) {
        int n = txt.length();
        int m = pat.length();
        
        vector<int> lps = computeLPS(pat);
        vector<int> resultIndices; // Stores starting indices where pattern is found
        
        int i = 0; // Index for txt
        int j = 0; // Index for pat
        
        while (i < n) {
            if (pat[j] == txt[i]) {
                i++;
                j++;
            }
            
            if (j == m) {
                resultIndices.push_back(i - j); // Match found at index (i - j)
                j = lps[j - 1]; // Reset j to find overlapping matches
            } 
            else if (i < n && pat[j] != txt[i]) {
                // Mismatch after j matches
                if (j != 0) {
                    j = lps[j - 1]; // Don't match lps[0..lps[j-1]] characters
                } else {
                    i++;
                }
            }
        }
        return resultIndices;
    }
};

int main() {
    KMPAlgorithm kmp;
    string txt = "ababcabcabababd";
    string pat = "ababd";
    
    vector<int> matches = kmp.searchPattern(pat, txt);
    
    cout << "Pattern found at indices: ";
    for (int idx : matches) {
        cout << idx << " ";
    }
    cout << endl;
    
    return 0;
}