#include <stdio.h>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int i;

    vector<int> score(4);
    for (i = 0; i < survey.size(); i++) {
        choices[i] -= 4;
        if (survey[i].compare("RT") == 0) {
            score[0] += choices[i];
        }
        else if (survey[i].compare("TR") == 0) {
            score[0] -= choices[i];
        }
        else if (survey[i].compare("CF") == 0) {
            score[1] += choices[i];
        }
        else if (survey[i].compare("FC") == 0) {
            score[1] -= choices[i];
        }
        else if (survey[i].compare("JM") == 0) {
            score[2] += choices[i];
        }
        else if (survey[i].compare("MJ") == 0) {
            score[2] -= choices[i];
        }
        else if (survey[i].compare("AN") == 0) {
            score[3] += choices[i];
        }
        else if (survey[i].compare("NA") == 0) {
            score[3] -= choices[i];
        }
    }

    if (score[0] > 0) {
        answer += "T";
    }
    else if (score[0] < 0) {
        answer += "R";
    }
    else {
        answer += "R";
    }

    if (score[1] > 0) {
        answer += "F";
    }
    else if (score[1] < 0) {
        answer += "C";
    }
    else {
        answer += "C";
    }

    if (score[2] > 0) {
        answer += "M";
    }
    else if (score[2] < 0) {
        answer += "J";
    }
    else {
        answer += "J";
    }

    if (score[3] > 0) {
        answer += "N";
    }
    else if (score[3] < 0) {
        answer += "A";
    }
    else {
        answer += "A";
    }
   
    return answer;
}