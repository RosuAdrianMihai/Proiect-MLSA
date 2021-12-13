#include<iostream>

using namespace std;

int maxim (int v[], int n){
    int max = v[0];
    for(int i = 1; i<n; i++){
        if(v[i]>max){
            max = v[i];
        }
    }
  return max; //elementul maxim
}

void countingSort(int v[], int n, int div){
    int output[n];  //vectorul in care punem elementele sortate dupa fiecare div
    int count[10] = {0}; //initializez cu 0 vectorul de frecventa

    for(int i = 0; i<n; i++)
    count[(v[i]/div)%10]++; //vector de frecventa

    for(int i = 1 ; i < 10; i++)
    count[i] += count[i-1]; //adun toate componentele din count v[i-1] in v[i]

    for(int i = n; i>=0; i--)
    {
        output[count[ (v[i]/div)%10]-1] = v[i]; // in pozitie pun elementul corespunzator din vector in urma sortarii in functie de cifra
        count [(v[i]/div)%10]--; //trec la o pozitia inferioara pt a pune elem.
    }

    for(int i = 0; i<n; i++)
    v[i] = output [i]; // sortez vectorul
}

void radixSort(int v[], int n){
    int nrMax = maxim(v, n);  //div este exponentul
    for(int div = 1; nrMax / div > 0 ; div *= 10){
        countingSort(v, n, div);
    }
}


int main(){
    int n, v[100], i;

    cout<<"Introduceti numarul de numere ce doriti sa fie sortate:"<<endl;
    cin>>n;

    cout<<"Introduceti valorile:"<<endl;

    for(i=0; i<n; i++){
    cout<<"v["<<i<<"] = ";
    cin>>v[i];
    }

    radixSort(v, n);

    for(int i = 0; i<n; i++)
    cout<<v[i]<<" ";
    return 0;
}