//
// Created by User on 28/6/2021.
//

#include "huffcoder.h"
/**
 *
 *
 * Metodo para decodificar el mensaje del servidor
 *
 * @param Recibe el mensaje codificado del server
 */
string huffcoder::decode(string code) {
    Split split;

    string OriginalMessage;

    vector<string> primervector  = split.split(code,'-');
    vector<string> datalist = split.split(primervector[0],',');
    vector<string> codelista = split.split(primervector[1],',');
    vector<string> messagecode = split.split(primervector[2],',');

    for(int i = 0; i<(int)messagecode.size(); i++){
        for(int j = 0; j<(int)codelista.size(); j++){
            if(messagecode[i] == codelista[j]){
                OriginalMessage += datalist[j];
            }
        }
    }

    return OriginalMessage;
}
/**
 *
 *
 * Metodo para dcodificar el mensaje a Huffman
 *
 * @param Recibe el mensaje cque se quiere mandar al server
 */
string huffcoder::encode(string text) {
    string originalText = text;
    HuffTree tree;
    string textaux;
    char pivot;
    int cont = 0;
    vector<string> datalist;
    vector<string> codelist;
    while((int)text.size()>0) {
        cont = 0;
        pivot = text[0];
        for (int i = 0; i < (int) text.size(); i++) {
            if(pivot == text[i]){
                cont+=1;
            }else{
                textaux+= text[i];
            }

        }
        string s(1,pivot);
        tree.Insert(new node(s,cont));
        text = textaux;
        textaux = "";
    }
    tree.Estructure_Tree();
    tree.printInorder();

    datalist = tree.datalist;
    codelist = tree.codelist;

    string encodeText = encodeOriginalText(originalText ,datalist,codelist);



    return serverstring(datalist,codelist,encodeText);
}

/**
 *
 *
 * Metodo para codificar el mensaje a Huffman, extrae toda la informacion
 *
 * @param Recibe el mensaje cque se quiere mandar al server
 */
string huffcoder::encodeOriginalText(string originaltext,vector<string>datalist,vector<string>codelist){
    string codeText;
    for(int i = 0; i<(int)originaltext.size();i++){
        for(int j = 0; j<(int)datalist.size();j++){
            if(originaltext[i] == datalist[j][0]){
                codeText+= (string) codelist[j] + (string) ",";
            }
        }
    }
    return codeText;
}
/**
 *
 *
 * Prepara el mensaje para ser enviado
 *
 * @param Recibe el mensaje cque se quiere mandar al server
 */
string huffcoder::serverstring(vector<string>datalist,vector<string>codelist,string encodeText){
    string encodeTextserver;

    for(int i = 0; i<(int)datalist.size();i++){
        encodeTextserver += datalist[i] + ',';
    }
    encodeTextserver += '-';

    for(int j = 0; j<(int)datalist.size();j++){
        encodeTextserver += codelist[j] + ',';
    }
    encodeTextserver += '-';

    encodeTextserver += encodeText;

    encodeTextserver += '-';

    return encodeTextserver;

}
