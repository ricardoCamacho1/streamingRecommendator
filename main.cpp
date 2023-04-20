#include <iostream>
#include <vector>
#include<string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Servicios.h"
//Proyecto Integ
//Daniela Jiménez Téllez A01654798
//Ricardo Camacho Castillo A01654132

using namespace std;

void SistemaRecomendador();

int main() 
{

  SistemaRecomendador();

}

void SistemaRecomendador(){
      int respuesta, x=0;
      string temp1;
      do{
        try{
          cout<< "¿En qué servicio quieres buscar?\n1) Netflix\n2) Prime\n3) Disney\n";
          getline(cin,temp1);
          stringstream(temp1)>>respuesta;

          if(respuesta!=1 && respuesta!=2 && respuesta!=3){
            throw 404;
          } 
          x=1;
        }catch(int error){
          cout<<"Error "<<error<<", sólo puedes ingresar los números de las opciones\n";
        }
        
      
      }while(x!=1);
        Recomendador recomendador = Recomendador();

        if (respuesta == 1){
          x=0;
          int busqueda;
          string pregunta, temp;
          do{
            try{
              cout<< "Que búsqueda quieres realizar?\n1) Título\n2) Edad\n3) Rating\n4) Rotten Tomatoes\n5) Año\n";
              getline(cin,temp);
              stringstream(temp) >> busqueda;
              if(busqueda!=1 && busqueda!=2 && busqueda!=3 && busqueda!=4 && busqueda!=5){
              throw 505;
              } 
              x=1;
              
            }catch(int error){
              cout<<"Error "<<error<<", sólo puedes ingresar los números de las opciones\n";
            }
          }while(x!=1);
          if(busqueda==1){
            cout << "Ingresa el título: ";
            getline(cin, pregunta);
            cout<<pregunta<<endl;
            recomendador.NconsultaPorTitulo(pregunta);
          } else if(busqueda == 2){
            cout << "Ingresa la edad con un + al final: ";
            getline(cin, pregunta);
            recomendador.NconsultaPorEdad(pregunta);
          }else if(busqueda==3){
            cout << "Ingresa la calificación:  ";
            getline(cin, pregunta);
            recomendador.NconsultaPorRating(pregunta);
          }else if(busqueda==4){
            cout << "Ingresa el porcentaje:  ";
            getline(cin, pregunta);
            recomendador.NconsultaPorTomatoes(pregunta);
          }else if(busqueda==5){
            cout << "Ingresa el años:  ";
            getline(cin, pregunta);
            recomendador.NconsultaPorYear(pregunta);
          }
        }
        else if (respuesta == 2)
        {
          x=0;
          int busqueda;
          string pregunta, temp;
          do{
            try{
              cout<< "Que búsqueda quieres realizar?\n1) Título\n2) Edad\n3) Rating\n4) Rotten Tomatoes\n5) Año\n";
              getline(cin,temp);
              stringstream(temp) >> busqueda;
              if(busqueda!=1 && busqueda!=2 && busqueda!=3 && busqueda!=4 && busqueda!=5){
              throw 505;
              } 
              x=1;
              
            }catch(int error){
              cout<<"Error "<<error<<", sólo puedes ingresar los números de las opciones\n";
            }
          }while(x!=1);
          if(busqueda==1){
            cout << "Ingresa el título: ";
            getline(cin, pregunta);
            recomendador.PconsultaPorTitulo(pregunta);
          } else if(busqueda == 2){
            cout << "Ingresa la edad con un + al final: ";
            getline(cin, pregunta);
            recomendador.PconsultaPorEdad(pregunta);
          }else if(busqueda==3){
            cout << "Ingresa la calificación:  ";
            getline(cin, pregunta);
            recomendador.PconsultaPorRating(pregunta);
          }else if(busqueda==4){
            cout << "Ingresa el porcentaje:  ";
            getline(cin, pregunta);
            recomendador.PconsultaPorTomatoes(pregunta);
          }else if(busqueda==5){
            cout << "Ingresa el años:  ";
            getline(cin, pregunta);
            recomendador.PconsultaPorYear(pregunta);
          }
        }
        else if (respuesta == 3)
        {
          x=0;
          int busqueda;
          string pregunta, temp;
          do{
            try{
              cout<< "Que búsqueda quieres realizar?\n1) Título\n2) Edad\n3) Rating\n4) Rotten Tomatoes\n5) Año\n";
              getline(cin,temp);
              stringstream(temp) >> busqueda;
              if(busqueda!=1 && busqueda!=2 && busqueda!=3 && busqueda!=4 && busqueda!=5){
              throw 505;
              } 
              x=1;
              
            }catch(int error){
              cout<<"Error "<<error<<", sólo puedes ingresar los números de las opciones\n";
            }
          }while(x!=1);
          if(busqueda==1){
            cout << "Ingresa el título: "<< endl;
            getline(cin, pregunta);
            recomendador.DconsultaPorTitulo(pregunta);
          } else if(busqueda == 2){
            cout << "Ingresa la edad con un + al final: "<< endl;
            getline(cin, pregunta);
            recomendador.DconsultaPorEdad(pregunta);
          }else if(busqueda==3){
            cout << "Ingresa la calificación:  ";
            getline(cin, pregunta);
            recomendador.DconsultaPorRating(pregunta);
          }else if(busqueda==4){
            cout << "Ingresa el porcentaje:  ";
            getline(cin, pregunta);
            recomendador.DconsultaPorTomatoes(pregunta);
          }else if(busqueda==5){
            cout << "Ingresa el años:  ";
            getline(cin, pregunta);
            recomendador.DconsultaPorYear(pregunta);
          }
        }
      
        cout<<recomendador;
 
    }