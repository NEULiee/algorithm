#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

struct city {
	int cityNum;
	string cityName;
	int people;

	struct city* head;	// 포함된 집합의 leader를 가리키는 포인터
	int total;			// query5를 구하기 위한 변수선언
};

int N, M, q;
int E = 0;									// edge 벡터를 탐색하기 위한 변수선언
bool finish = false;
list<city> cities[1000001];					// 도시번호 별 리스트 생성
vector<pair<int, pair<int, int>>> path;     // 도로길이, 도시1, 도시2
vector<pair<int, pair<int, int>>> mstPath;  // MST

int getHeadNum(int);						// 포함된 집합의 leader의 도시번호를 얻는 함수
int _union(int, int);						// union
int getLength();							// mstPath의 총 포장도로 길이를 구하는 함수
bool compare(pair<int, pair<int, int>>, pair<int, pair<int, int>>);	// sort를 위한 비교함수
void query1();
void query2();
void query3();
void query4();
void query5();
void query6();

int main() {
	int cityNum, people;
	string cityName;
	cin >> N >> M >> q;
	for (int i = 0; i < N; i++) {
		cin >> cityNum >> cityName >> people;
		city c = { cityNum, cityName, people , NULL , 0 };

		cities[cityNum].push_back(c);								// 도시번호 list에 자기자신 삽입
		cities[cityNum].begin()->head = &cities[cityNum].front();	// head도 자기자신으로 설정
	}
	int num1, num2, pathLen;
	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2 >> pathLen;
		path.push_back(make_pair(pathLen, make_pair(num1, num2)));	// 도로벡터에 삽입
	}

	sort(path.begin(), path.end(), compare);						// 제일 작은 길이의 포장도로부터 합치기 위해 정렬

	char query;
	for (int i = 0; i < q; i++) {
		if (finish) {		
			return 0;
		}
		cin >> query;
		if (query == 'N') {
			query1();
		}
		else if (query == 'L') {
			query2();
		}
		else if (query == 'I') {
			query3();
		}
		else if (query == 'F') {
			query4();
		}
		else if (query == 'W') {
			query5();
		}
		else if (query == 'Q') {
			query6();
		}
	}
	return 0;
}

int getHeadNum(int v) {							// v가 포함된 집합의 리더 도시번호를 반환해주는 함수 (find)
	return cities[v].begin()->head->cityNum;
}

int _union(int lead, int sub) {		// union 함수,	lead: 붙여질 리스트의 리더 도시번호
									//				sub: 붙일 리스트의 리더 도시번호
	city c = cities[sub].front();
											
	list<city>::iterator iter;
	for (iter = cities[sub].begin(); iter != cities[sub].end(); ++iter) {	// iterator를 통해서 sub 리스트 요소들의 head를 
		iter->head = &cities[lead].front();									// lead 리스트의 head로 바꿔준다.
		cities[iter->cityNum].begin()->head = &cities[lead].front();
	}

	cities[lead].splice(cities[lead].end(), cities[sub]);					// sub 리스트를 lead 리스트 맨끝에 붙인다.

	cities[sub].push_back(c);												// head를 바로 찾을 수 있게 sub리스트에 처음 값을 놔둔다.
	cities[sub].begin()->head = &cities[lead].front();

	cities[lead].begin()->total += cities[sub].begin()->total;				// query5번. 합쳐진 도로 길이를 더해준다.

	return cities[lead].size();												// query3을 위해 합쳐진 리스트의 사이즈 반환
}

int getLength() {		// MST안에 들어있는 전체 도로길이를 반환
	int len = 0;
	int size = mstPath.size();
	for (int i = 0; i < size; i++) {
		len += mstPath[i].first;
	}
	return len;
}

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	int p1 = cities[a.second.first].begin()->people + cities[a.second.second].begin()->people;	// 인구수 합
	int p2 = cities[b.second.first].begin()->people + cities[b.second.second].begin()->people;
	int cityNum1 = a.second.first < a.second.second ? a.second.first : a.second.second;			// 도시번호
	int cityNum2 = b.second.first < b.second.second ? b.second.first : b.second.second;

	if (a.first == b.first && p1 == p2) {	// 도로길이가 같고, 인구 수가 같을 때, 도시번호 비교
		return cityNum1 < cityNum2;
	}
	else if (a.first == b.first) {			// 도로길이가 같을 때, 인구수 비교
		return !(p1 < p2);
	}
	else {									// 도로길이 비교
		return a.first < b.first;
	}
}

void query1() {												// 1. 중간정보 출력: 특정 도시가 포함된 연결리스트의 내부 정보 파악
	int v, k, count = 0;
	cin >> v >> k;
	int headNum = getHeadNum(v);
	int size = cities[headNum].size();

	if (size <= k) {										// 리스트에 k번째 원소가 없을 때	
		cout << "no exist" << "\n";
		return;
	}

	list<city>::iterator iter = cities[headNum].begin();;	// iterator로 리스트에서 찾은 후 출력
	while (1) {
		if (count == k) {
			int x = iter->cityNum;
			string y = iter->cityName;
			cout << x << " " << y << "\n";
			return;
		}
		iter++;
		count++;
	}
}

void query2() {								// 2. 중간정보 출력 : 특정 도시가 포함된 연결리스트의 크기
	int v;
	cin >> v;

	int headNum = getHeadNum(v);			// head 리스트의 사이즈 출력
	cout << cities[headNum].size() << "\n";
}

void query3() {								// 3. 중간단계: Kruskal 알고리즘에서 하나의 반복(iteration) 진행
	int v1 = path[E].second.first;			// 정렬한 포장도로 길이 중에서 제일 작은 길이의 정보를 가져온후,
	int v2 = path[E].second.second;			// 다음 벡터에 접근하기위해 변수 E의 값 증가
	int pathLen = path[E].first;
	E++;

	int h1 = getHeadNum(v1);				// 가져온 정보의 두 도시의 head를 찾아주고, 만약 같다면 같은 집합이므로 return
	int h2 = getHeadNum(v2);
	if (h1 == h2) {
		cout << "not union\n";
		return;
	}

	int lead, sub;							// weighted-union heuristic 위한 조건문
	int size1 = cities[h1].size();
	int size2 = cities[h2].size();
	if (size1 > size2) {
		lead = h1;
		sub = h2;
	}
	else if (size1 < size2) {
		lead = h2;
		sub = h1;
	}
	else {
		if (h1 < h2) {
			lead = h1;
			sub = h2;
		}
		else {
			lead = h2;
			sub = h1;
		}
	}

	cities[lead].begin()->total += pathLen;	// query5번. 합쳐진 도로 길이를 더해준다.
	int newSize = _union(lead, sub);		// union
	mstPath.push_back(make_pair(pathLen, make_pair(v1, v2)));	// union이 성공하면 MST에 넣어준다.

	int size = cities[lead].size();			// 합쳐진 리스트의 사이즈가 도시의 수와 같다면 MST 완성, MST 정보와 함께 return
	if (size == N) {
		int len = getLength();
		cout << lead << " " << newSize << " " << lead << " " << len << "\n";
		finish = true;
		return;
	}

	cout << lead << " " << newSize << "\n";	// MST가 완성되지 않았다면 합쳐진 정보 return
	return;
}

void query4() {							// 4. 중간정보 출력: 두 도시가 같은 집합에 속하는지 확인
	int V1, V2;	
	cin >> V1 >> V2;
	int h1 = getHeadNum(V1);
	int h2 = getHeadNum(V2);

	if (h1 == h2) {						// 두 도시의 head를 비교
		cout << "True " << h1 << "\n";
	}
	else {
		cout << "False " << h1 << " " << h2 << "\n";
	}
}

void query5() {									// 5. 중간정보 출력 : 임의의 도시를 포함하는 집합의 모든 포장도로의 길이
	int v, pathLen = 0;
	cin >> v;

	int h = getHeadNum(v);

	cout << cities[h].begin()->total << "\n";	// head의 total 값 출력
}

void query6() {								// 6. 알고리즘의 나머지 단계 연속수행 및 프로그램 종료
	int v1, v2, pathLen, h1, h2, lead, sub;

	while (1) {								// MST가 완성될 때까지 union 작업 반복
		v1 = path[E].second.first;
		v2 = path[E].second.second;
		pathLen = path[E].first;
		E++;

		h1 = getHeadNum(v1);
		h2 = getHeadNum(v2);
		if (h1 == h2) {						// head 도시번호가 같다면 cycle, union을 수행하지않고 다음 도로로 넘어간다.
			continue;
		}												// 이하 query3과 동일
		if (cities[h1].size() > cities[h2].size()) {
			lead = h1;
			sub = h2;
		}
		else if (cities[h1].size() < cities[h2].size()) {
			lead = h2;
			sub = h1;
		}
		else {
			if (h1 < h2) {
				lead = h1;
				sub = h2;
			}
			else {
				lead = h2;
				sub = h1;
			}
		}
		_union(lead, sub);
		mstPath.push_back(make_pair(pathLen, make_pair(v1, v2)));
		cities[lead].begin()->total += pathLen;

		int size = cities[lead].size();
		if (size == N) {
			int len = getLength();
			cout << lead << " " << len << "\n";
			finish = true;
			return;
		}
	}
}