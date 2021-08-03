//Boyer - Moore

#include <iostream>

using namespace std;
void badCharacter(string str , int pat_size, int badchar[256] )
{
    int i;
    for(i=0; i< 256; i++){
        badchar[i]= -1; //khởi tạo các giá trị đêu là
    }
    for(i=0;i<pat_size;i++)
    {
        badchar[(int) str[i]]=i;
    }
}

void boyer_moore(string text, string pattern)
{
    int pat_size = pattern.size();
    int txt_size = text.size();
    int badchar[256];
    badCharacter(pattern, pat_size , badchar);
    int vitri = 0;
    while(vitri <= (txt_size - pat_size)){
        int j = pat_size -1 ;
        while(j>=0 && pattern[j] == text[vitri+ j])
        {
            j--;
        }
        if(j<0)
        {
            cout<<"Chuoi P xuat hien o vi tri: "<<vitri<<endl;
            break;

        }
        else{
            vitri+= max(1, j - badchar[text[vitri+j]]);
        }
    }
}
int main()
{
    string text= "ABAAABCDASJHDHUQWEHNNMXCBJHASAJKDHDSDAAFSFCXZSAEQW";
    string pattern = "AJKD";
    boyer_moore(text, pattern);
    return 0;
}
