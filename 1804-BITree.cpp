#include <iostream>
using namespace std;


int getSum(int BITree[], int index)
{
    int sum = 0; 
    index = index + 1;

    while (index>0)
    {

        sum += BITree[index];

        index -= index & (-index);
    }
    return sum;
}


void updateBIT(int BITree[], int n, int index, int val)
{
    index = index + 1;

    while (index <= n)
    {

    BITree[index] += val;

    index += index & (-index);
    }
}

int *constructBITree(int arr[], int n)
{
    int *BITree = new int[n+1];
    for (int i=1; i<=n; i++)
        BITree[i] = 0;

    for (int i=0; i<n; i++)
        updateBIT(BITree, n, i, arr[i]);


    return BITree;
}



int main(){

int tamanho;
cin >> tamanho;

int frequencia[tamanho];
for(int i = 0; i < tamanho; i++){
    cin >> frequencia[i];
}

int n = sizeof(frequencia)/sizeof(frequencia[0]);

int *BITree = constructBITree(frequencia, n);


char a;
int b;

while(cin>>a>>b){
    if(b <= tamanho && b >= 1){

        if(a=='a'){

        updateBIT(BITree, n, b-1, -(frequencia[b-1]) );
        frequencia[b-1] = 0;

            }else{

        cout << getSum(BITree, b-2) << endl;

            }

        }
    }

}
