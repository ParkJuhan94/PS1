#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<vector<int>> textQueries(vector<string> sentences, vector<string> queries) {
    int i, j, flag = 0;
    int n = queries.size();
    vector<vector<int>> res;
    vector<int> vec;
    vector<int> nullVec = {-1};

    for (i = 0; i < queries.size(); i++) {
        stringstream ss(queries[i]);
        ss.str(queries[i]);

        string word;
        while (ss >> word) {
            printf("word : %s\n", word.c_str());
            for (j = 0; j < sentences.size(); j++) {
                stringstream sss(sentences[j]);
                sss.str(sentences[j]);

                string stWord;                
                while (sss >> stWord) {
                    printf("stword : %s\n", stWord.c_str());
                    if (word == stWord) {
                        vec.push_back(j);                        
                        flag = 1;
                    }                    
                }
                
            }     
           
        }
        res.push_back(vec);
        vec.clear();
        if (flag == 0) res.push_back(nullVec);
        flag = 0;
    }

    return res;
}

int main() {
    int i, j;
    vector<string> sentences = { "how it was done" ,"are you how", "it goes to", "goes done are it" };
    vector<string> queries = {"done it", "it"};
    vector<vector<int>> a = textQueries(sentences, queries);

    for (i = 0; i < a.size(); i++) {
        for (j = 0; j < a[i].size(); j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

/*
int main()
{
    string word = "aaccbba";
    int k = 2;

    string result = compressWord(word, k);

    printf("%s\n", result.c_str());

    return 0;
}
*/

