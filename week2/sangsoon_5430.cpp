#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool _forward;		// forward가 true면 순방향, false면 역방향
vector<string> v;
int start_i, end_i;

void init() {
	_forward = true;
	v.clear();

	start_i = 0;
	end_i = -1;
}

void parse(string &s) {
	// 문자열의 처음과 끝에 있는 [, ]를 삭제
	s.erase(s.begin() + 0);
	s.erase(s.end() - 1);

	if (s.empty()) return;

	int pos, cur_pos = 0;
	s += ",";	// 마지막 원소까지 구분해주기 위해 ,추가
	string delimeter = ",";

	while ((pos = s.find(delimeter, cur_pos)) != string::npos) {
		int len = pos - cur_pos;
		string e = s.substr(cur_pos, len);
		v.push_back(e);
		
		cur_pos = pos + 1;
	}

	end_i = v.size() - 1;
}

bool do_command(char command) {
	switch (command)
	{
	case 'R':
		_forward = !_forward;
		break;
	case 'D':
		if (start_i > end_i) return false;	// 배열이 빈 경우 에러
		
		if (_forward) start_i++;			// 순방향인 경우 start인덱스 더하고 
		else end_i--;						// 역방향인 경우 end인덱스를 빼준다

		break;
	}

	return true;
}

void printResult() {
	if (start_i > end_i) {	// 배열이 비어있는 경우
		cout << "[]\n";
		return;
	}

	string res = "[";
	
	string e;
	if (_forward) {	// 순방향인 경우 start_i 부터 end_i까지 프린트
		while (start_i <= end_i) {
			e = v[start_i];
			res += e;
			res += ',';

			start_i++;
		}
	}
	else {	// 역방향인 경우 end_i 부터 start_i까지 역방향 프린트
		while (start_i <= end_i) {
			e = v[end_i];
			res += e;
			res += ',';

			end_i--;
		}
	}

	res.erase(res.end() - 1);	// 마지막 콤마를 빼준다
	res += ']';

	cout << res << "\n";
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int testcase;
	cin >> testcase;

	string commands, elements;
	int n_elements;

	while (testcase-- > 0) {
		cin >> commands >> n_elements >> elements;

		init();
		parse(elements);
		
		bool ret = true;
		for (char comm : commands) {
			ret = do_command(comm);

			if (!ret) break;	// 에러 발생
		}

		if (ret) printResult();
		else cout << "error\n";
	}
}