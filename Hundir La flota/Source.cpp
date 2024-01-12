#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int iFilas = 10;
const int iColumnas = 10;


int main()
{
    char cTableroJugador1[iFilas][iColumnas];
    char cTableroJugador2[iFilas][iColumnas];
    char cBarcosJugador1[iFilas][iColumnas];
    char cBarcosJugador2[iFilas][iColumnas];
    bool bPartida = false;
    srand(static_cast<unsigned>(time(nullptr)));  // Cambio en la semilla de srand

    int iNumerobarcos[4] = { 3, 4, 5, 6 }; 

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
        int iFilas6j1 = rand() % 10;
        int iColumnas6j1 = rand() % 10;
        int iDireccion6j1 = 1 + rand() % 2; // 1 = Vertical 2 = Horizontal

        if (iDireccion6j1 == 1)
        {

            if (iFilas6j1 + iNumerobarcos[3] <= iFilas)
            { // Vertical
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador1[iFilas6j1 + i][iColumnas6j1] = '6';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador1[iFilas6j1 - i][iColumnas6j1] = '6';
                }
            }
        }
        else
        {
            if (iColumnas6j1 + iNumerobarcos[3] <= iColumnas)
            { // Horizontal
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador1[iFilas6j1][iColumnas6j1 + i] = '6';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[3]; i++)
                {
                    cBarcosJugador1[iFilas6j1][iColumnas6j1 - i] = '6';
                }
            }
        }

        bBarco6j1 = true;
    }
    // Barco 5
    while (bBarco5j1 == false)
    {
        int iFilas5j1 = rand() % 10;
        int iColumnas5j1 = rand() % 10;
        int iDireccion5j1 = 1 + rand() % 2;
        bool bVerificacion5j1 = false;

        while (bVerificacion5j1 == false) // Verificacion
        {
            int iContador = 0;

            if (iDireccion5j1 == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    if (iFilas5j1 + i >= 10 || cBarcosJugador1[iFilas5j1 + i][iColumnas5j1] != '~')
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
                    if (iColumnas5j1 + i >= 10 || cBarcosJugador1[iFilas5j1][iColumnas5j1 + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion5j1 = true;
            }
            else
            {
                iFilas5j1 = rand() % 10;
                iColumnas5j1 = rand() % 10;
            }
        }

        if (iDireccion5j1 == 1)
        {
            if (iFilas5j1 + iNumerobarcos[2] <= 10) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador1[iFilas5j1 + i][iColumnas5j1] = '5';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador1[iFilas5j1 - i][iColumnas5j1] = '5';
                }
            }
        }
        else
        {
            if (iColumnas5j1 + iNumerobarcos[2] <= 10) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador1[iFilas5j1][iColumnas5j1 + i] = '5';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[2]; i++)
                {
                    cBarcosJugador1[iFilas5j1][iColumnas5j1 - i] = '5';
                }
            }
        }

        bBarco5j1 = true;
    }
    // Barco 4
    while (bBarco4j1 == false)
    {
        int iFilas4j1 = rand() % 10;
        int iColumnas4j1 = rand() % 10;
        int iDireccion4j1 = 1 + rand() % 2;
        bool bVerificacion4j1 = false;

        while (bVerificacion4j1 == false) // Verificacion
        {
            int iContador = 0;

            if (iDireccion4j1 == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    if (iFilas4j1 + i >= 10 || cBarcosJugador1[iFilas4j1 + i][iColumnas4j1] != '~')
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
                    if (iColumnas4j1 + i >= 10 || cBarcosJugador1[iFilas4j1][iColumnas4j1 + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion4j1 = true;
            }
            else
            {
                iFilas4j1 = rand() % 10;
                iColumnas4j1 = rand() % 10;
            }
        }

        if (iDireccion4j1 == 1)
        {
            if (iFilas4j1 + iNumerobarcos[1] <= 10) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador1[iFilas4j1 + i][iColumnas4j1] = '4';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador1[iFilas4j1 - i][iColumnas4j1] = '4';
                }
            }
        }
        else
        {
            if (iColumnas4j1 + iNumerobarcos[1] <= 10) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador1[iFilas4j1][iColumnas4j1 + i] = '4';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[1]; i++)
                {
                    cBarcosJugador1[iFilas4j1][iColumnas4j1 - i] = '4';
                }
            }
        }

        bBarco4j1 = true;
    }

    // Barco 3
    while (bBarco3j1 == false)
    {
        int iFilas3j1 = rand() % 10;
        int iColumnas3j1 = rand() % 10;
        int iDireccion3j1 = 1 + rand() % 2;
        bool bVerificacion3j1 = false;

        while (bVerificacion3j1 == false) // Verificacion
        {
            int iContador = 0;

            if (iDireccion3j1 == 1) // Verificacion Vertical
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    if (iFilas3j1 + i >= 10 || cBarcosJugador1[iFilas3j1 + i][iColumnas3j1] != '~')
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
                    if (iColumnas3j1 + i >= 10 || cBarcosJugador1[iFilas3j1][iColumnas3j1 + i] != '~')
                    {
                        iContador++;
                        break;
                    }
                }
            }

            if (iContador == 0)
            {
                bVerificacion3j1 = true;
            }
            else
            {
                iFilas3j1 = rand() % 10;
                iColumnas3j1 = rand() % 10;
            }
        }

        if (iDireccion3j1 == 1)
        {
            if (iFilas3j1 + iNumerobarcos[0] <= 10) // Vertical
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador1[iFilas3j1 + i][iColumnas3j1] = '3';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador1[iFilas3j1 - i][iColumnas3j1] = '3';
                }
            }
        }
        else
        {
            if (iColumnas3j1 + iNumerobarcos[0] <= 10) // Horizontal
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador1[iFilas3j1][iColumnas3j1 + i] = '3';
                }
            }
            else
            {
                for (int i = 0; i < iNumerobarcos[0]; i++)
                {
                    cBarcosJugador1[iFilas3j1][iColumnas3j1 - i] = '3';
                }
            }
        }

        bBarco3j1 = true;
    }


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
};




