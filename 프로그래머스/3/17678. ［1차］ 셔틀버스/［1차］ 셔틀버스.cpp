#include <algorithm>
#include <string>
#include <map>
#include <vector>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	multimap<string, vector<string>> shuttle_mm;
	sort(timetable.begin(), timetable.end());  // timetable 오름차순으로

	for (int i = 0; i < n; i++) {
        if (i == 0) {
            shuttle_mm.insert({"09:00", vector<string>()});
        }
        else
        {
            if (9 + i * t / 60 < 10) {      // 10시 이전이면
                if (i * t % 60 < 10)        // 분이 10분 이전이면
					shuttle_mm.insert({"0" + to_string(9 + i * t / 60) + ":0" + to_string(i * t % 60), vector<string>()});
                else                        // 분이 10분 이후이면
                    shuttle_mm.insert({"0" + to_string(9 + i * t / 60) + ":" + to_string(i * t % 60), vector<string>()});
            }
            else {                          // 10시 이후이면
				if (i * t % 60 < 10)
					shuttle_mm.insert({to_string(9 + i * t / 60) + ":0" + to_string(i * t % 60), vector<string>()});
				else                 
					shuttle_mm.insert({to_string(9 + i * t / 60) + ":" + to_string(i * t % 60), vector<string>()});
            }
		}
	}

	for (auto& iter : shuttle_mm) {
		for (int j = 0; j < timetable.size(); j++) {
			if (iter.first >= timetable[j] &&  // 배차 시간이 크루 도착 시간보다 늦거나 같고
				iter.second.size() < m) 	   // 탑승 가능하면
            {
                // 셔틀에 탑승한 사람은 추가하고 timetable에서 제거
				iter.second.push_back(timetable[j]);
				timetable.erase(timetable.begin() + j);
				j--;
			}
		}
	}

    for(auto& iter : shuttle_mm) {
		if (iter.second.size() < m) {   // value에 남는 자리가 있으면
			answer = iter.first;	    // answer = 셔틀 시간
		}
		else {                          // value에 남는 자리가 없으면
			string last_time = iter.second.back();

            // answer = last time에서 1분을 뺀 시간
            answer = last_time.substr(0, 2) + ":" + to_string(stoi(last_time.substr(3, 2)) - 1);
            if (stoi(answer.substr(3, 2)) < 0) {    // 분이 0보다 작으면
                answer = to_string(stoi(answer.substr(0, 2)) - 1) + ":59";   // 시간에서 1을 빼고 분은 59로
                if (stoi(answer.substr(0, 2)) < 10) {       // 시간이 10보다 작으면
                    answer = "0" + answer;                  // 앞에 0을 붙임
                }
            }
            if(stoi(answer.substr(3)) < 10) {       // 분이 10보다 작으면
				answer = answer.substr(0, 3) + "0" + answer.substr(3);	    // 앞에 0을 붙임
			}
        }
    }
    return answer;
}