#include <iostream>
#include <fstream>

using namespace std;

void funcion(float mp[] [5], int n, float pm, string vecna[], float md[][5], int ve[]) 
{
    int maxd = 0;
    int maxp = 0;
    int cliMaxp = 0;
    int cliMaxd = 0;
    int vec[n] {0};
    const int a = 5;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < a; j++)
        {
            if (mp [i] [j] > pm)
            {
                vec[i]++;
                cout << vecna[i] << ": " << vecna[j + 8] << ", " << mp [i] [j] << "Kg" << endl;
                if (vec[i] > maxp)
                {
                    maxp = vec[i];
                    cliMaxp = i;
                } 
            }
        }
    }
    cout << "=====================================" << endl;

    cout << "El cliente con mayor cantidad de productos que superaron los 13000Kg fue: " << vecna[cliMaxp] << endl;
    for (int k = 0; k < a; k++)
    {
        if(md[cliMaxp] [k + 8] > maxd)
        {
            maxd = md[cliMaxp] [k + 8];
            cliMaxd = k;
        }
        cout << vecna[k + 8] << ": " << md [cliMaxp] [k + 8] << "Km" << endl;
    }
    cout << "=====================================" << endl;

    cout << "El producto con mayor recorrido de: " << vecna[cliMaxp] << " fue: " << vecna[cliMaxd] << endl << "Producto el cual tuvo un total de: " << ve[cliMaxd] << " entregas" << endl;

}

int main()
{
    int a = 0;
    const int nom = 8;
    const int art = 5;
    const float pesoMax = 13000;
    float mdist [nom] [art] {0};
    float mpeso [nom] [art] {0};
    int vecen [art] {0};
    string nmb;
    string vecna[nom + art];
    ifstream datos;
    ifstream nombres;

    datos.open("Datos.txt");
    if (!datos)
    {
        cout << "No se abrió correctamente el archivo! " << endl;
        return 1;
    }

    int cli, pro;
    float peso, dist;
    while (datos >> cli >> pro >> peso >> dist)
    {
        mpeso[cli] [pro] += peso;
        mdist[cli] [pro] += dist;
        vecen [pro]++;
    }
    datos.close();

    nombres.open("Nombres.txt");
    if (!nombres)
    {
        cout << "No se abrió correctamente el archivo! " << endl;
        return 1;
    }

    while (nombres >> nmb)
    {
        vecna [a] = nmb;
        a++;
        
    }
    nombres.close();
    funcion(mpeso, nom, pesoMax, vecna, mdist, vecen);
}
