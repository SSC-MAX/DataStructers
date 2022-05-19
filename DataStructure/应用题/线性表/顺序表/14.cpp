#define INT_MAX 0x7fffffff

int getAbs(int a)
{
    if (a>0)
    {
        return a;
    }else{
        return -a;
    }
}

bool ifMin(int a, int b, int c)
{
    if (a<b && b<c)
    {
        return true;
    }else{
        return false;
    }
    
}

int getMin(int A[], int a_length ,int B[], int b_length,int C[], int c_length)
{
    int i=0,j=0,k=0,D_min=INT_MAX;
    int distance;
    while (i<a_length && j<b_length && k<c_length)
    {
        distance = getAbs(A[i]-B[j])+getAbs(B[j]-C[k])+getAbs(A[i]-C[k]);
        if (distance<D_min)
        {
            D_min = distance;
        }
        if (ifMin(i,j,k))
        {
            i++;
        }else if (ifMin(j,i,k))
        {
            j++;
        }else{
            k++;
        }
    }
    return D_min;
}