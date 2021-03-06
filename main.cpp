#include <iostream>
#include <fstream>

using namespace std;

string arrPlainText[8];
string arrP10[10];
string arrP8[8];
string arrP9[8];
string arrEP1[8];
string arrEP2[8];
string arrIP[8];
string arrP4[4];
string result[8];
int modo = 1, fB = 0;

int matrizS0[4][4] =  {
                        {1,0,3,2},
                        {3,2,1,0},
                        {0,2,1,3},
                        {3,1,3,2}

                        };

int matrizS1[4][4] =    {
                        {0,1,2,3},
                        {2,0,1,3},
                        {3,0,1,0},
                        {2,1,0,3}

                        };

int binToDEC(string bin){

    if(bin == "00"){
        return 0;
    }else if(bin == "01"){
        return 1;
    }else if(bin == "10"){
        return 2;
    }else if(bin == "11"){
        return 3;
    }
    return -1;
}

string decToBin(int dec){

    if(dec == 0){
        return "00";
    }else if(dec == 1){
        return "01";
    }else if(dec == 2){
        return "10";
    }else if(dec == 3){
        return "11";
    }
    return "00";
}

void matrizEP1(){

    string rowT1 = arrEP1[0] + arrEP1[3];
    string colT1 = arrEP1[1] + arrEP1[2];
    string rowT2 = arrEP1[4] + arrEP1[7];
    string colT2 = arrEP1[5] + arrEP1[6];

    int resultA = matrizS0[binToDEC(rowT1)][binToDEC(colT1)];
    int resultB = matrizS1[binToDEC(rowT2)][binToDEC(colT2)];

    if(fB == 0){
    cout << "Resultado A = " << resultA << endl;
    cout << "Resultado B = " << resultB << endl;
    }
    string P4 = decToBin(resultA) + decToBin(resultB);
    arrP4[0] = P4[1];
    arrP4[1] = P4[3];
    arrP4[2] = P4[2];
    arrP4[3] = P4[0];

    ///XOR P4
    for(int j = 0; j < 4; j++){
            if(arrP4[j] == arrIP[j]){
                arrP4[j] = '0';
            }else{
                arrP4[j] = '1';
            }
    }

}

void matrizEP2(){

    string rowT1 = arrEP2[0] + arrEP2[3];
    string colT1 = arrEP2[1] + arrEP2[2];
    string rowT2 = arrEP2[4] + arrEP2[7];
    string colT2 = arrEP2[5] + arrEP2[6];

    int resultA = matrizS0[binToDEC(rowT1)][binToDEC(colT1)];
    int resultB = matrizS1[binToDEC(rowT2)][binToDEC(colT2)];
    if(fB == 0){
    cout << "Resultado A = " << resultA << endl;
    cout << "Resultado B = " << resultB << endl;
    }
    string P4 = decToBin(resultA) + decToBin(resultB);
    arrP4[0] = P4[1];
    arrP4[1] = P4[3];
    arrP4[2] = P4[2];
    arrP4[3] = P4[0];

    if(fB == 0){
    cout << endl;
    cout << "P4 =";
    for(int z = 0; z < 4; z++){
        cout << arrP4[z];
    }
    cout << endl;

    cout << endl;
    cout << "IP =";
    for(int z = 0; z < 4; z++){
        cout << arrIP[z];
    }
    cout << endl;


    ///XOR P4
    cout << "XORSITO ";
    }
    for(int j = 0; j < 4; j++){
            if(arrP4[j] == arrIP[j]){
                arrP4[j] = '0';
            }else{
                arrP4[j] = '1';
            }
        if(fB == 0){
        cout << arrP4[j];
        }
    }
    if(fB == 0){
    cout << endl;
    }


}

void mostrar(){
    for(int y = 0; y < 10; y++){
        cout << arrP10[y] << " ";
    }
    cout << endl;
}

void mostrarP8(){
    for(int y = 0; y < 8; y++){
        cout << arrP8[y] << " ";
    }
    cout << endl;
}
void mostrarP9(){
    for(int i = 0; i < 8; i++){
        cout << arrP9[i] << " ";
    }
    cout << endl;
}

void IP(string PT){

    arrIP[0] = PT[1];
    arrIP[1] = PT[5];
    arrIP[2] = PT[2];
    arrIP[3] = PT[0];
    arrIP[4] = PT[3];
    arrIP[5] = PT[7];
    arrIP[6] = PT[4];
    arrIP[7] = PT[6];

}

void EP1(){

    arrEP1[0] = arrIP[7];
    arrEP1[1] = arrIP[4];
    arrEP1[2] = arrIP[5];
    arrEP1[3] = arrIP[6];
    arrEP1[4] = arrIP[5];
    arrEP1[5] = arrIP[6];
    arrEP1[6] = arrIP[7];
    arrEP1[7] = arrIP[4];

}

void EP2(){

    arrEP2[0] = arrIP[7];
    arrEP2[1] = arrIP[4];
    arrEP2[2] = arrIP[5];
    arrEP2[3] = arrIP[6];
    arrEP2[4] = arrIP[5];
    arrEP2[5] = arrIP[6];
    arrEP2[6] = arrIP[7];
    arrEP2[7] = arrIP[4];

}

void P10(string llave){
    arrP10[0] = llave[2];
    arrP10[1] = llave[4];
    arrP10[2] = llave[1];
    arrP10[3] = llave[6];
    arrP10[4] = llave[3];
    arrP10[5] = llave[9];
    arrP10[6] = llave[0];
    arrP10[7] = llave[8];
    arrP10[8] = llave[7];
    arrP10[9] = llave[5];

}

void P8(){
    arrP8[0] = arrP10[5];
    arrP8[1] = arrP10[2];
    arrP8[2] = arrP10[6];
    arrP8[3] = arrP10[3];
    arrP8[4] = arrP10[7];
    arrP8[5] = arrP10[4];
    arrP8[6] = arrP10[9];
    arrP8[7] = arrP10[8];

}

void P9(){
    arrP9[0] = arrP10[5];
    arrP9[1] = arrP10[2];
    arrP9[2] = arrP10[6];
    arrP9[3] = arrP10[3];
    arrP9[4] = arrP10[7];
    arrP9[5] = arrP10[4];
    arrP9[6] = arrP10[9];
    arrP9[7] = arrP10[8];

}

void XOREP1(){

    if(modo == 1){

        for(int j = 0; j < 8; j++){
            if(arrP8[j] == arrEP1[j]){
                arrEP1[j] = '0';
            }else{
                arrEP1[j] = '1';
            }
        }

    }


   if(modo == 2){
        for(int j = 0; j < 8; j++){
            if(arrP9[j] == arrEP1[j]){
                arrEP1[j] = '0';
            }else{
                arrEP1[j] = '1';
            }
        }
   }
    if(fB == 0){
     for(int i = 0; i < 8; i++){
        cout << arrEP1[i] << " ";
    }
    cout << endl;
    }
}


void XOREP2(){

    if(modo == 1){

        for(int j = 0; j < 8; j++){
            if(arrP9[j] == arrEP2[j]){
                arrEP2[j] = '0';
            }else{
                arrEP2[j] = '1';
            }
        }

    }


   if(modo == 2){
        for(int j = 0; j < 8; j++){
            if(arrP8[j] == arrEP2[j]){
                arrEP2[j] = '0';
            }else{
                arrEP2[j] = '1';
            }
        }
   }
    if(fB == 0){
     for(int i = 0; i < 8; i++){
        cout << arrEP2[i] << " ";
    }
    cout << endl;
    }

}





void moverIzq(int a, int b){
    string aux;

    for(int x = a; x < b; x++){

        if(x == a){
            aux = arrP10[x];
            arrP10[x] = arrP10[x+1];
        }else if(x == b-1){
            arrP10[x] = aux;
        }else{
            arrP10[x] = arrP10[x+1];
        }
    }
}




int main()
{
    ifstream par("D:/Escritorio/Pares.txt");
    ifstream key("D:/Escritorio/Llaves.txt");
    string llavePrincipal;
    bool NotOurKey = false;
    string Text;
    string Aux;
    string Pares;
    string plainText[8];
    cout << "1 = ENCRIPTAR" << endl;
    cout << "2 = DESENCRIPTAR" << endl;
    cout << "3 = Fuerza Bruta" << endl;
    cin >> modo;
    cin.ignore();

    if(modo != 3){
        cout << "Ingrese llave" << endl;
        getline(cin,llavePrincipal);
        cout << "Ingrese Text" << endl;
        getline(cin, Text);

        IP(Text);
        EP1();

        P10(llavePrincipal);
        mostrar();
        moverIzq(0,5);
        mostrar();
        moverIzq(5,10);
        mostrar();
        P8();
        cout << "P8 = ";
        mostrarP8();
        cout << endl;
        moverIzq(0,5);
        mostrar();
        moverIzq(5,10);
        mostrar();
        moverIzq(0,5);
        mostrar();
        moverIzq(5,10);
        mostrar();
        P9();
        cout << "P8 = ";
        mostrarP9();
        cout << endl;

        cout << "XOREP1" << endl;
        XOREP1();
        matrizEP1();

        arrIP[0] = arrIP[4];
        arrIP[1] = arrIP[5];
        arrIP[2] = arrIP[6];
        arrIP[3] = arrIP[7];
        arrIP[4] = arrP4[0];
        arrIP[5] = arrP4[1];
        arrIP[6] = arrP4[2];
        arrIP[7] = arrP4[3];

        EP2();
        XOREP2();
        matrizEP2();

        arrIP[0] = arrP4[0];
        arrIP[1] = arrP4[1];
        arrIP[2] = arrP4[2];
        arrIP[3] = arrP4[3];

        result[0] = arrIP[3];
        result[1] = arrIP[0];
        result[2] = arrIP[2];
        result[3] = arrIP[4];
        result[4] = arrIP[6];
        result[5] = arrIP[1];
        result[6] = arrIP[7];
        result[7] = arrIP[5];

        cout << endl;
        for(int v = 0; v < 8; v++){
            cout << result[v];
        }
        cout << endl;
    }else{

        Text = "00000000";
        fB = 1;
        modo = 2;

        while(!key.eof()){

            key >> llavePrincipal;

            P10(llavePrincipal);
            moverIzq(0,5);
            moverIzq(5,10);
            P8();

            moverIzq(0,5);
            moverIzq(5,10);
            moverIzq(0,5);
            moverIzq(5,10);
            P9();



            while(!par.eof()){

                NotOurKey = false;

                par >> Aux;
                plainText[0] = Aux[0];
                plainText[1] = Aux[1];
                plainText[2] = Aux[2];
                plainText[3] = Aux[3];
                plainText[4] = Aux[4];
                plainText[5] = Aux[5];
                plainText[6] = Aux[6];
                plainText[7] = Aux[7];

                Text[0] = Aux[9];
                Text[1] = Aux[10];
                Text[2] = Aux[11];
                Text[3] = Aux[12];
                Text[4] = Aux[13];
                Text[5] = Aux[14];
                Text[6] = Aux[15];
                Text[7] = Aux[16];


                IP(Text);
                EP1();

                XOREP1();
                matrizEP1();

                arrIP[0] = arrIP[4];
                arrIP[1] = arrIP[5];
                arrIP[2] = arrIP[6];
                arrIP[3] = arrIP[7];
                arrIP[4] = arrP4[0];
                arrIP[5] = arrP4[1];
                arrIP[6] = arrP4[2];
                arrIP[7] = arrP4[3];

                EP2();
                XOREP2();
                matrizEP2();

                arrIP[0] = arrP4[0];
                arrIP[1] = arrP4[1];
                arrIP[2] = arrP4[2];
                arrIP[3] = arrP4[3];

                result[0] = arrIP[3];
                result[1] = arrIP[0];
                result[2] = arrIP[2];
                result[3] = arrIP[4];
                result[4] = arrIP[6];
                result[5] = arrIP[1];
                result[6] = arrIP[7];
                result[7] = arrIP[5];

                for(int v = 0; v < 8; v++){

                    if(result[v] != plainText[v]){
                        NotOurKey = true;
                        break;
                    }
                }

                if(NotOurKey == true){
                    par.clear();
                    par.seekg(0, par.beg );
                    break;

                }


            }///Par while

            if(NotOurKey == false){
                break;
            }

        }///key while
        cout << endl;
        cout << "LLAVE RESULTADO = " <<     llavePrincipal << endl;
    }


    par.close();
    key.close();
}
