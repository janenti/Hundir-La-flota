#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

#define iFilas 10
#define iColumnas 10


int main()
{
    char cTableroJugador1[iFilas][iColumnas];
    char cTableroJugador2[iFilas][iColumnas];
    char cBarcosJugador1[iFilas][iColumnas];
    char cBarcosJugador2[iFilas][iColumnas];
    bool bPartida = false;
    srand(static_cast<unsigned>(time(nullptr)));  // Semilla de srand
    int iNumerobarcos[4] = { 3, 4, 5, 6 }; 
    int iContador1 = 0; //Contador Gameplay
    int iContador2 = 0; //Contador Gameplay
    

    for (int i = 0; i < iFilas; ++i)
    {
        for (int j = 0; j < iColumnas; ++j)
        {
            cTableroJugador1[i][j] = '~';
            cTableroJugador2[i][j] = '~';
            cBarcosJugador1[i][j] = '~';
            cBarcosJugador2[i][j] = '~';
        }
    }
    bool bBarco6j1 = false;  
    bool bBarco6j2 = false;
    bool bBarco5j1 = false;
    bool bBarco5j2 = false;
    bool bBarco4j1 = false;
    bool bBarco4j2 = false;
    bool bBarco3j1 = false;
    bool bBarco3j2 = false;
    // Generar Barcos
    //Jugador 1
    // Barco 6
    while (bBarco6j1 == false)
    {
        int iFilasb = rand() % 10;
        int iColumnasb = rand() % 10;
        int iDireccion = 1 + rand() % 2; // 1 = Vertical 2 = Horizontal

        if (iDireccion == 1)
        {

            if (iFilasb + iNumerobarcos[3] <= iFilas)
            { // Vertical
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador1[iFilasb + i][iColumnasb] = '6';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador1[iFilasb - i][iColumnasb] = '6';
                }
            }
        }
        else
        {
            if (iColumnasb + iNumerobarcos[3] <= iColumnas)
            { // Horizontal
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador1[iFilasb][iColumnasb + i] = '6';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador1[iFilasb][iColumnasb - i] = '6';
                }
            }
        }

        bBarco6j1 = true;
    }
    // Barco 5
    while (bBarco5j1 == false)
    {
        int iFilasb = rand() % 10; 
        int iColumnasb = rand() % 10; 
        int iDireccion = 1 + rand() % 2;
        bool bVerificacion = false;

        while (bVerificacion == false) // Verificacion, he usado chatgpt para corregir parte del codigo de verificacion porque no me funcionaba bien, almenos la estructura si que la hice yo.
        {
            int iContador = 0;

            if (iDireccion == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    if (iFilasb + i >= 10 || cBarcosJugador1[iFilasb + i][iColumnasb] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }
            else // Verificacion Horizontal
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    if (iColumnasb + i >= 10 || cBarcosJugador1[iFilasb][iColumnasb + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion = true;
            }
            else
            {
                iFilasb = rand() % 10;
                iColumnasb = rand() % 10;
            }
        }

        if (iDireccion == 1)
        {
            if (iFilasb + iNumerobarcos[2] <= iFilas) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador1[iFilasb + i][iColumnasb] = '5';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador1[iFilasb - i][iColumnasb] = '5';
                }
            }
        }
        else
        {
            if (iColumnasb + iNumerobarcos[2] <= iColumnas) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador1[iFilasb][iColumnasb + i] = '5';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador1[iFilasb][iColumnasb - i] = '5';
                }
            }
        }

        bBarco5j1 = true;
    }
    // Barco 4
    while (bBarco4j1 == false)
    {
        int iFilasb = rand() % 10;
        int iColumnasb = rand() % 10;
        int iDireccion = 1 + rand() % 2;
        bool bVerificacion = false;

        while (bVerificacion == false) // Verificacion
        {
            int iContador = 0;

            if (iDireccion == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    if (iFilasb + i >= iFilas || cBarcosJugador1[iFilasb + i][iColumnasb] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }
            else // Verificacion Horizontal
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    if (iColumnasb + i >= iColumnas || cBarcosJugador1[iFilasb][iColumnasb + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion = true;
            }
            else
            {
                iFilasb = rand() % 10; 
                iColumnasb = rand() % 10; 
            }
        }

        if (iDireccion == 1)
        {
            if (iFilasb + iNumerobarcos[1] <= iFilas) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador1[iFilasb + i][iColumnasb] = '4';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador1[iFilasb - i][iColumnasb] = '4';
                }
            }
        }
        else
        {
            if (iColumnasb + iNumerobarcos[1] <= iColumnas) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador1[iFilasb][iColumnasb + i] = '4';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador1[iFilasb][iColumnasb - i] = '4';
                }
            }
        }

        bBarco4j1 = true;
    }

    // Barco 3
    while (bBarco3j1 == false)
    {
        int iFilasb = rand() % 10;
        int iColumnasb = rand() % 10;
        int iDireccion = 1 + rand() % 2;
        bool bVerificacion = false;

        while (bVerificacion == false) // Verificacion
        {
            int iContador = 0;

            if (iDireccion == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    if (iFilasb + i >= iFilas || cBarcosJugador1[iFilasb + i][iColumnasb] != '~') 
                    {
                        iContador++;
                        break;
                    }
                }
            }
            else // Verificacion Horizontal
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    if (iColumnasb + i >= iColumnas || cBarcosJugador1[iFilasb][iColumnasb + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion = true;
            }
            else
            {
                iFilasb = rand() % 10;
                iColumnasb = rand() % 10;
            }
        }

        if (iDireccion == 1)
        {
            if (iFilasb + iNumerobarcos[0] <= iFilas) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador1[iFilasb + i][iColumnasb] = '3';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador1[iFilasb - i][iColumnasb] = '3';
                }
            }
        }
        else
        {
            if (iColumnasb + iNumerobarcos[0] <= iColumnas) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador1[iFilasb][iColumnasb + i] = '3';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador1[iFilasb][iColumnasb - i] = '3';
                }
            }
        }

        bBarco3j1 = true;
    }

    //Jugador2
        // Barco 6
    while (bBarco6j2 == false)
    {
        int iFilasb = rand() % 10;
        int iColumnasb = rand() % 10;
        int iDireccion = 1 + rand() % 2; // 1 = Vertical 2 = Horizontal

        if (iDireccion == 1)
        {

            if (iFilasb + iNumerobarcos[3] <= iFilas)
            { // Vertical
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador2[iFilasb + i][iColumnasb] = '6';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador2[iFilasb - i][iColumnasb] = '6';
                }
            }
        }
        else
        {
            if (iColumnasb + iNumerobarcos[3] <= iColumnas)
            { // Horizontal
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador2[iFilasb][iColumnasb + i] = '6';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador2[iFilasb][iColumnasb - i] = '6';
                }
            }
        }

        bBarco6j2 = true;
    }
    // Barco 5
    while (bBarco5j2 == false)
    {
        int iFilasb = rand() % 10;
        int iColumnasb = rand() % 10;
        int iDireccion = 1 + rand() % 2;
        bool bVerificacion = false;

        while (bVerificacion == false) // Verificacion
        {
            int iContador = 0;

            if (iDireccion == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    if (iFilasb + i >= 10 || cBarcosJugador2[iFilasb + i][iColumnasb] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }
            else // Verificacion Horizontal
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    if (iColumnasb + i >= 10 || cBarcosJugador2[iFilasb][iColumnasb + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion = true;
            }
            else
            {
                iFilasb = rand() % 10;
                iColumnasb = rand() % 10;
            }
        }

        if (iDireccion == 1)
        {
            if (iFilasb + iNumerobarcos[2] <= iFilas) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador2[iFilasb + i][iColumnasb] = '5';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador2[iFilasb - i][iColumnasb] = '5';
                }
            }
        }
        else
        {
            if (iColumnasb + iNumerobarcos[2] <= iColumnas) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador2[iFilasb][iColumnasb + i] = '5';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador2[iFilasb][iColumnasb - i] = '5';
                }
            }
        }

        bBarco5j2 = true;
    }
    // Barco 4
    while (bBarco4j2 == false)
    {
        int iFilasb = rand() % 10;
        int iColumnasb = rand() % 10;
        int iDireccion = 1 + rand() % 2;
        bool bVerificacion = false;

        while (bVerificacion == false) // Verificacion
        {
            int iContador = 0;

            if (iDireccion == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    if (iFilasb + i >= iFilas || cBarcosJugador2[iFilasb + i][iColumnasb] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }
            else // Verificacion Horizontal
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    if (iColumnasb + i >= iColumnas || cBarcosJugador2[iFilasb][iColumnasb + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion = true;
            }
            else
            {
                iFilasb = rand() % 10;
                iColumnasb = rand() % 10;
            }
        }

        if (iDireccion == 1)
        {
            if (iFilasb + iNumerobarcos[1] <= iFilas) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador2[iFilasb + i][iColumnasb] = '4';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador2[iFilasb - i][iColumnasb] = '4';
                }
            }
        }
        else
        {
            if (iColumnasb + iNumerobarcos[1] <= iColumnas) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador2[iFilasb][iColumnasb + i] = '4';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador2[iFilasb][iColumnasb - i] = '4';
                }
            }
        }

        bBarco4j2 = true;
    }

    // Barco 3
    while (bBarco3j2 == false)
    {
        int iFilasb = rand() % 10;
        int iColumnasb = rand() % 10;
        int iDireccion = 1 + rand() % 2;
        bool bVerificacion = false;

        while (bVerificacion == false) // Verificacion
        {
            int iContador = 0;

            if (iDireccion == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    if (iFilasb + i >= iFilas || cBarcosJugador2[iFilasb + i][iColumnasb] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }
            else // Verificacion Horizontal
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    if (iColumnasb + i >= iColumnas || cBarcosJugador2[iFilasb][iColumnasb + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion = true;
            }
            else
            {
                iFilasb = rand() % 10;
                iColumnasb = rand() % 10;
            }
        }

        if (iDireccion == 1)
        {
            if (iFilasb + iNumerobarcos[0] <= iFilas) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador2[iFilasb + i][iColumnasb] = '3';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador2[iFilasb - i][iColumnasb] = '3';
                }
            }
        }
        else
        {
            if (iColumnasb + iNumerobarcos[0] <= iColumnas) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador2[iFilasb][iColumnasb + i] = '3';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador2[iFilasb][iColumnasb - i] = '3';
                }
            }
        }

        bBarco3j2 = true;
    }
    //Gameplay
    while (bPartida == false)
    {
        int iVertical1;
        int iHorizontal1;
        int iVertical2;
        int iHorizontal2;
        bool b1turno = false;
            while (b1turno == false)
            {
                // Tablero Jugador 1

                cout << "Tablero del Jugador 1:" << endl;
                for (int i = 0; i < iFilas; ++i)
                {
                    for (int j = 0; j < iColumnas; ++j)
                    {
                        cout << cBarcosJugador1[i][j] << ' ';
                    }
                    cout << endl;
                }

                // Tablero Jugador 2

                cout << "\nTablero del Jugador 2:" << endl;
                for (int i = 0; i < iFilas; ++i)
                {
                    for (int j = 0; j < iColumnas; ++j)
                    {
                        cout << cBarcosJugador2[i][j] << ' ';
                    }
                    cout << endl;
                }
                std::this_thread::sleep_for(std::chrono::seconds(3)); //Para esto he usado chatgpt
                system("cls");
                b1turno = true;
            }
            // Tablero Jugador 1

            cout << "\nTablero del Jugador 1:" << endl;
            for (int i = 0; i < iFilas; ++i) 
            {
                for (int j = 0; j < iColumnas; ++j) 
                {
                    cout << cTableroJugador1[i][j] << ' '; 
                }
                cout << endl;
            }

            // Tablero Jugador 2

            cout << "\nTablero del Jugador 2:" << endl;
            for (int i = 0; i < iFilas; ++i)
            {
                for (int j = 0; j < iColumnas; ++j)
                {
                    cout << cTableroJugador2[i][j] << ' ';
                }
                cout << endl;
            }
            //Jugador uno
            cout << "Jugador 1 inserta coordenada vertical:\n";
            cin >> iVertical1; 
            cout << "Jugador 1 inserta coordenada horizontal:\n";
            cin >> iHorizontal1; 
            
            if (cBarcosJugador1[iVertical1][iHorizontal1] != '~')
            {
                cout << "\nTocado!!!!";
                cTableroJugador1[iVertical1][iHorizontal1] = 'O';
                iContador1++;
            }
            else
            {
                cout << "\nAgua";
                cTableroJugador1[iVertical1][iHorizontal1] = 'X';
            }
            if (iContador1 == 25)
            {   
                system("cls"); 
                cout << "\nVictoria!!!!";   
                bPartida = true;
            }
            //Jugador Dos
            cout << "\nJugador 2 inserta coordenada vertical:\n";
            cin >> iVertical2; 
            cout << "Jugador 1 inserta coordenada horizontal:\n";
            cin >> iHorizontal2; 
            
            if (cBarcosJugador2[iVertical2][iHorizontal2] != '~')
            {
                cout << "\nTocado!!!!\n"; 
                cTableroJugador2[iVertical2][iHorizontal2] = 'O';
                iContador1++;
            }
            else
            {
                cout << "\nAgua\n"; 
                cTableroJugador2[iVertical2][iHorizontal2] = 'X';
            }
            if (iContador2 == 25)
            {
                system("cls");  
                cout << "\nVictoria!!!!"; 
                bPartida = true;
            }
            system("cls");
    }

};