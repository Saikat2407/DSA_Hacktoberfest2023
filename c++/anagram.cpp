#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char str1[20], str2[20];
    int len1, len2, found=0, not_found=0;
    cout << "Enter the First Word: ";
    cin >> str1;
    cout << "Enter the Second Word: ";
    cin >> str2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    if(len1 == len2)
    {
        for(int i=0; i<len1; i++)
        {
            found = 0;
            for(int j=0; j<len1; j++)
            {
                if(str1[i] == str2[j])
                {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            {
                not_found = 1;
                break;
            }
        }
        if(not_found == 1)
            cout << "\n" << str1 << " & " << str2 << " are not Anagrams";
        else
            cout<<"\n" << str1 << " & " << str2 << " are Anagrams";
    }
    else
        cout<<"\nCharacter count Mismatched!";
    cout<<endl;
    return 0;
}