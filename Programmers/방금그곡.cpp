#include <string>
#include <vector>
#include <iostream>
using namespace std;

int t;

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    for (int i = 0; i < musicinfos.size(); i++)
    {
        string str = musicinfos[i];

        //노래 이름
        string name = "";
        int pnt = 12;
        while (str[pnt] != ',')
            name += str[pnt++];
        pnt++;

        //음악
        string music = "";
        while (pnt != str.size())
            music += str[pnt++];

        //재생시간
        int start_min = 0;
        int end_min = 0;
        string a = "";
        a += str[0];
        a += str[1];
        string b = "";
        b += str[6];
        b += str[7];
        int t_sub = atoi(b.c_str()) - atoi(a.c_str());
        while(t_sub--)
            end_min += 60;
        start_min += (str[3] - '0') * 10;
        start_min += (str[4] - '0');
        end_min += (str[9] - '0') * 10;
        end_min += (str[10] - '0');
        int min = end_min - start_min;

        
        //흘러나온 음
        string music_min = "";
        int pt = 0;
        for (int j = 0; j < min; j++)
        {
            music_min += music[pt++];
            if (pt == music.size())
                pt = 0;
            if(music[pt]=='#')
                music_min += music[pt++];
            if (pt == music.size())
                pt = 0;
        }

        if(music_min.size() < m.size()) continue;
        for (int j = 0; j <= music_min.size() - m.size()+1; j++)
        {
            if (m[0] == music_min[j])
            {
                int pt_a = 0;
                int pt_b = j;
                bool posi = true;
                while (pt_a != m.size())
                {
                    if (pt_b == music_min.size())
                    {
                        posi = false;
                        break;
                    }
                    
                    if (m[pt_a] != music_min[pt_b])
                    {
                        posi = false;
                        break;
                    }
                    pt_a++;
                    pt_b++;
                }
                
                if (posi == false) continue;

                if (pt_b < music_min.size())
                    if (music_min[pt_b] == '#')
                        posi = false;


                if (pt_a==m.size() && posi && t < min)
                {
                    t = min;
                    answer = name;
                    break;
                }
            }
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

	cout << solution("ABCDEFG",{"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"})<<"\n";
    cout << solution( "CC", { "03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" });

    return 0;
}
