//
// Created by User on 28/6/2021.
//

#ifndef NEW_FOLDER_HUFFCODER_H
#define NEW_FOLDER_HUFFCODER_H
#include "HuffTree.h"
#include "Split.h"
using namespace std;
class huffcoder {
public:

    string encode(string);
    string decode(string);





    string encodeOriginalText(string originaltext, vector<string> datalist, vector<string> codelist);

    string serverstring(vector<string> datalist, vector<string> codelist, string encodeText);
};


#endif //NEW_FOLDER_HUFFCODER_H
