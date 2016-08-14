#include <stdio.h>


int main()
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    char gene[500000]="";
    int ct=0;
    int i=0;
    int lim[2]={0};   //记录最长的稳定基因序列
    int gene_num[4]={0};
    int temp[4]={0};

    scanf("%d",&ct);
    scanf("%s",gene);

    int n=ct/4;          //计算稳定基因出现的次数

    for(i=0;i<ct;i++)     //
    {

           if(gene[i]=='A')
             if(gene_num[0]==n)
               break;
             else
               gene_num[0]++;
            else if(gene[i]=='T')
              if(gene_num[1]==n)
                break;
              else
                gene_num[1]++;
            else if(gene[i]=='C')
              if(gene_num[2]==n)
                break;
              else
                gene_num[2]++;
            else if(gene[i]=='G')
              if(gene_num[3]==n)
                break;
              else
                gene_num[3]++;
           lim[0]++;

    }

    int x = ct-1;
    lim[1]=i;

    while(--i>=0)
    {
       for(;x>=0;x--)     //从尾部加
       {

            if(gene[x]=='A')
                if(gene_num[0]==n)
                  break;
                else
                  gene_num[0]++;
            else if(gene[x]=='T')
                if(gene_num[1]==n)
                  break;
                else
                  gene_num[1]++;
            else if(gene[x]=='C')
               if(gene_num[2]==n)
                  break;
                else
                 gene_num[2]++;
            else if(gene[x]=='G')
                if(gene_num[3]==n)
                  break;
                else
                  gene_num[3]++;
            lim[1]++;
        }
        if(lim[1]>lim[0])
          lim[0]=lim[1];

       if(gene[i]=='A')     //从头部取出
         gene_num[0]--;
       else if(gene[i]=='T')
         gene_num[1]--;
       else if(gene[i]=='C')
         gene_num[2]--;
       else if(gene[i]=='G')
         gene_num[3]--;
       lim[1]--;         //长度减一

    }



    printf("%d",ct-lim[0]);
    return 0;
}

