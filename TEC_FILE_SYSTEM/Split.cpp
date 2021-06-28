//
// Created by User on 28/6/2021.
//

#include "Split.h"


 vector<string> Split::split(string text, char flag) {
    string subtext;
    vector<string> splitvector;
    for (int i = 0; i<(int)text.size(); i++){
        if(text[i]== flag){
            splitvector.push_back(subtext);
            subtext="";
        }else {
            subtext += text[i];
        }
    }
    return splitvector;

}