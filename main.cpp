#include <iostream>
#include <ctime>
using namespace std;
string campo[3][10][10];
string lettere[11]={" ","A","B","C","D","E","F","G","H","I","L"};
string comand[]={"sw-p1","sw-p2","set-p1","reset-p1","reset-p2","reset-all","help","start","gen-p1","gen-p2","cls","attacca [X] [Y]"};
string caract="o";
string hashtag="#";
void out_campo(int x){
    if(x==2||x==1)
        cout << "PLAYER >> 2"<<endl;
    else
        cout << "PLAYER >> 1"<<endl;
    for(int i=0;i<10;i++){
        if(i==0){
            for(int z=1;z<11;z++)
            cout << lettere[z]<<" ";
            cout << endl;
        }
        for(int j=0;j<10;j++){
            cout << campo[x][i][j]<<" ";
        }
        cout << i+1;
        cout << endl;
    }
}

void in(string& x,int& x_,int& y,int& dim, string& dir,bool& ok,int& incrociatore,int& sottomarino,int& corazzata,int& portaerei){
        cin >> x;
        cin >> y;
        cin >> dim;
        cin >> dir;

    if((dim==2&&incrociatore==0)||(dim==3&&sottomarino==0)||(dim==4&&corazzata==0)||(dim==5&&portaerei==0)){
        cout <<"Nave già usata"<<endl;
        ok=false;
    }
    if(dim>5||dim<2){
        cout << "nave troppo grande o piccola"<<endl;
        ok=false;
    }

    for(int j=1;j<11;j++)
        if(lettere[j]==x)
            x_=j;
    for(int j=0;j<dim;j++){
            if(dir=="e")
            if(campo[0][y-1][x_-1+j]==hashtag || y>10 || x_+j>10||y<1 || x_+j<1)
                ok=false;
            if(dir=="o")
            if(campo[0][y-1][x_-1-j]==hashtag|| y>10 || x_-j>10||y<1 || x_-j<1)
                ok=false;
            if(dir=="n")
            if(campo[0][y-1-j][x_-1]==hashtag|| y-j>10 || x_>10||y-j<1 || x_<1)
                ok=false;
            if(dir=="s")
            if(campo[0][y-1+j][x_-1]==hashtag|| y+j>10 || x_>10||y+j<1 || x_<1)
                ok=false;
    }
}
void set_in(){
    int portaerei=1,corazzata=2,sottomarino=3,incrociatore=4;
    while(portaerei!=0||sottomarino!=0||corazzata!=0||incrociatore!=0){
        string x;int x_;int y;int dim;string dir;bool ok=true;
        out_campo(0);
        cout<<"\nPortaerei:"<< portaerei<<endl
            <<"Corazzata:"<<corazzata<<endl
            <<"Sottomarino:"<<sottomarino<<endl
            <<"Incrociatore:"<<incrociatore<<endl;
        in(x,x_,y,dim,dir,ok,incrociatore,sottomarino,corazzata,portaerei);
        system("cls");
        if(ok==true){
            for(int j=0;j<dim;j++){
                if(dir=="e"){
                campo[0][y-1][x_-1+j]=hashtag;
                }
                if(dir=="o")
                campo[0][y-1][x_-1-j]=hashtag;
                if(dir=="n")
                campo[0][y-1-j][x_-1]=hashtag;
                if(dir=="s")
                campo[0][y-1+j][x_-1]=hashtag;
            }

            switch(dim){
                case 2:
                incrociatore--;
                break;
                case 3:
                sottomarino--;
                break;
                case 4:
                corazzata--;
                break;
                case 5:
                portaerei--;
                break;
            }

        }else
            cout << "ERRORE \n";
    }
}
void gen_campo(int campo_){
    int portaerei=1,corazzata=2,sottomarino=3,incrociatore=4;
    int n=1;
    int x;int y;int dim;int dir;
    srand((unsigned)time(0));
    while(n<=10){
            bool ok=true;
            x=rand()%10+1;
            y=rand()%10+1;
            dim=rand()%5+2;
            dir=rand()%4+1;
            //controlla
            if((x==1&&dir==2)||(x==10&&dir==1)||(y==1&&dir==3)||(y==10&&dir==4))
                    ok=false;
            if((dim==2&&incrociatore==0)||(dim==3&&sottomarino==0)||(dim==4&&corazzata==0)||(dim==5&&portaerei==0))
                ok=false;
            else
            switch(dir){
            case 1://e
                for(int j=0;j<dim;j++)
                    if(campo[campo_][y-1][x-1+j]==hashtag || y>10 || x+j>10||y<1 || x+j<1)
                        ok=false;
            break;
            case 2://o
                for(int j=0;j<dim;j++)
                    if(campo[campo_][y-1][x-1-j]==hashtag|| y>10 || x+j>10||y<1 || x-j<1)
                        ok=false;
            break;
            case 3://n
                for(int j=0;j<dim;j++)
                    if(campo[campo_][y-1-j][x-1]==hashtag|| y-j>10 || x>10||y-j<1 || x<1)
                        ok=false;
            break;
            case 4://s
                for(int j=0;j<dim;j++)
                    if(campo[campo_][y-1+j][x-1]==hashtag|| y+j>10 || x>10||y+j<1 || x<1)
                        ok=false;
            break;
            }
            //------------------
            if(ok==true){
                cout << n << " ";
                n++;
                switch(dir){
                case 1:
                    for(int j=0;j<dim;j++)
                        campo[campo_][y-1][x-1+j]=hashtag;
                break;
                case 2:
                    for(int j=0;j<dim;j++)
                        campo[campo_][y-1][x-1-j]=hashtag;
                break;
                case 3:
                    for(int j=0;j<dim;j++)
                        campo[campo_][y-1-j][x-1]=hashtag;
                break;
                case 4:
                    for(int j=0;j<dim;j++)
                        campo[campo_][y-1+j][x-1]=hashtag;
                break;
                }

                switch(dim){
                    case 2:
                        incrociatore--;
                    break;
                    case 3:
                        sottomarino--;
                    break;
                    case 4:
                        corazzata--;
                    break;
                    case 5:
                        portaerei--;
                    break;
                }

            }
    }
    cout << "GENERATED\n";
}

void reset(int x){
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++){
        campo[x][i][j]=caract;
    }
}
void attacca(string x,int y,bool& attacco){
    int x_=0;
    for(int j=0;j<11;j++)
        if(lettere[j]==x)
            x_=j;
    if(campo[1][y-1][x_-1]==hashtag){
        campo[2][y-1][x_-1]="x";
        campo[1][y-1][x_-1]="x";
        cout << "LUI: colpito\n";
        attacco=true;
    }else{
        campo[1][y-1][x_-1]="/";
        campo[2][y-1][x_-1]="/";
        cout << "LUI: mancato\n";
        attacco=false;
    }
}
void attacca_nemico(int x,int y,bool& attacco){
    if(campo[0][y-1][x-1]==hashtag){
        campo[0][y-1][x-1]="x";
        cout << "TU: colpito\t["<<lettere[x]<<","<<y<<"]\n";
        attacco=true;
    }else{
        campo[0][y-1][x-1]="/";
        cout << "TU: mancato\t["<<lettere[x]<<","<<y<<"]\n";
        attacco=false;
    }
}
void fine_(bool& fine){
    int c=0;int a=0;
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++){
        if(campo[0][i][j]!=hashtag){
            c++;
            if(c==100){
                fine=true;
                cout << "HAI PERSO!\n";
            }
        }
        if(campo[1][i][j]!=hashtag){
            a++;
            if(a==100){
                fine=true;
                cout << "HAI VINTO!\n";
            }
        }
    }
}
void comandi(string comando,bool& start,bool& fine,bool& cheat){
    if(comando=="cls")
        system("cls");
    else if(comando=="sw-p1")
        out_campo(0);
    else if(comando=="sw-p2"){
        if(cheat==true)
            out_campo(1);
        if((start==false||fine==false)&&cheat==false)
            out_campo(2);
    }else if(comando=="gen-p1"&&(start==false||cheat==true))
        gen_campo(0);
    else if(comando=="gen-p2"&&(start==false||cheat==true))
        gen_campo(1);
    else if(comando=="reset-p1"&&(start==false||cheat==true))
        reset(0);
    else if(comando=="reset-p2"&&(start==false||cheat==true))
        reset(1);
    else if(comando=="reset-all"&&(start==false||cheat==true)){
        reset(0);reset(1);
    }
    else if(comando=="set-p1"&&(start==false||cheat==true))
        set_in();
    else if(comando=="help")
        for(int i=0;i<12;i++)
            cout << comand[i]<<endl;
    else if(comando=="start"&&start==false)
        start=true;
    else if(comando=="stop"&&fine==false){
        fine=true;start=true;
    }
    else if(comando=="attacca"&&(start==true||cheat==true)){
            string att;string x;int x_;int y;bool attacco=true;
            while(attacco==true){
                    fine_(fine);
                    cin >> x;
                    cin >> y;
                attacca(x,y,attacco);
            }
            attacco=true;
            while(attacco==true){
                x_=rand()%10+1;
                y=rand()%10+1;
                attacca_nemico(x_,y,attacco);
            }
    }else if(comando=="cheat:"){
        cin >> comando;
        if(comando=="true")
            cheat=true;
        if(comando=="false")
            cheat=false;
    }else{
        cout << "\acomando non trovato! digita help per avere la lista dei comandi\n";
    }
}

int main(){
    srand((unsigned)time(0));
    system("color 30");
    for(int x=0;x<3;x++)
    for(int i=0;i<10;i++)
    for(int j=0;j<10;j++){
        campo[x][i][j]=caract;
    }
    string comando;
    bool start=false,fine=false,cheat=false;
    while(start==false){
        cin >> comando;
        comandi(comando,start,fine,cheat);
    }
    system("cls");
    while(fine==false){
        fine_(fine);
        if(fine==true)
            break;
        cin >> comando;
        comandi(comando,start,fine,cheat);
    }
    system("pause");
}
