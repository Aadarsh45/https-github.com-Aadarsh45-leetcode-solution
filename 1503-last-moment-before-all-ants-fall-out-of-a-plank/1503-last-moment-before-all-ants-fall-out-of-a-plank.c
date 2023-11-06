int getLastMoment(int n, int* left, int leftSize, int* right, int rightSize) 
{
    int l=0, r=0;
    for(register i=0; i<rightSize; i++) if (n-l>right[i]) l=n-right[i];
    for(register i=0; i<leftSize; i++) if (r<left[i]) r=left[i];
    return (r>l)?r:l;
}