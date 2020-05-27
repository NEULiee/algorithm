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

	struct city* head;	// ���Ե� ������ leader�� ����Ű�� ������
	int total;			// query5�� ���ϱ� ���� ��������
};

int N, M, q;
int E = 0;									// edge ���͸� Ž���ϱ� ���� ��������
bool finish = false;
list<city> cities[1000001];					// ���ù�ȣ �� ����Ʈ ����
vector<pair<int, pair<int, int>>> path;     // ���α���, ����1, ����2
vector<pair<int, pair<int, int>>> mstPath;  // MST

int getHeadNum(int);						// ���Ե� ������ leader�� ���ù�ȣ�� ��� �Լ�
int _union(int, int);						// union
int getLength();							// mstPath�� �� ���嵵�� ���̸� ���ϴ� �Լ�
bool compare(pair<int, pair<int, int>>, pair<int, pair<int, int>>);	// sort�� ���� ���Լ�
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

		cities[cityNum].push_back(c);								// ���ù�ȣ list�� �ڱ��ڽ� ����
		cities[cityNum].begin()->head = &cities[cityNum].front();	// head�� �ڱ��ڽ����� ����
	}
	int num1, num2, pathLen;
	for (int i = 0; i < M; i++) {
		cin >> num1 >> num2 >> pathLen;
		path.push_back(make_pair(pathLen, make_pair(num1, num2)));	// ���κ��Ϳ� ����
	}

	sort(path.begin(), path.end(), compare);						// ���� ���� ������ ���嵵�κ��� ��ġ�� ���� ����

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

int getHeadNum(int v) {							// v�� ���Ե� ������ ���� ���ù�ȣ�� ��ȯ���ִ� �Լ� (find)
	return cities[v].begin()->head->cityNum;
}

int _union(int lead, int sub) {		// union �Լ�,	lead: �ٿ��� ����Ʈ�� ���� ���ù�ȣ
									//				sub: ���� ����Ʈ�� ���� ���ù�ȣ
	city c = cities[sub].front();
											
	list<city>::iterator iter;
	for (iter = cities[sub].begin(); iter != cities[sub].end(); ++iter) {	// iterator�� ���ؼ� sub ����Ʈ ��ҵ��� head�� 
		iter->head = &cities[lead].front();									// lead ����Ʈ�� head�� �ٲ��ش�.
		cities[iter->cityNum].begin()->head = &cities[lead].front();
	}

	cities[lead].splice(cities[lead].end(), cities[sub]);					// sub ����Ʈ�� lead ����Ʈ �ǳ��� ���δ�.

	cities[sub].push_back(c);												// head�� �ٷ� ã�� �� �ְ� sub����Ʈ�� ó�� ���� ���д�.
	cities[sub].begin()->head = &cities[lead].front();

	cities[lead].begin()->total += cities[sub].begin()->total;				// query5��. ������ ���� ���̸� �����ش�.

	return cities[lead].size();												// query3�� ���� ������ ����Ʈ�� ������ ��ȯ
}

int getLength() {		// MST�ȿ� ����ִ� ��ü ���α��̸� ��ȯ
	int len = 0;
	int size = mstPath.size();
	for (int i = 0; i < size; i++) {
		len += mstPath[i].first;
	}
	return len;
}

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	int p1 = cities[a.second.first].begin()->people + cities[a.second.second].begin()->people;	// �α��� ��
	int p2 = cities[b.second.first].begin()->people + cities[b.second.second].begin()->people;
	int cityNum1 = a.second.first < a.second.second ? a.second.first : a.second.second;			// ���ù�ȣ
	int cityNum2 = b.second.first < b.second.second ? b.second.first : b.second.second;

	if (a.first == b.first && p1 == p2) {	// ���α��̰� ����, �α� ���� ���� ��, ���ù�ȣ ��
		return cityNum1 < cityNum2;
	}
	else if (a.first == b.first) {			// ���α��̰� ���� ��, �α��� ��
		return !(p1 < p2);
	}
	else {									// ���α��� ��
		return a.first < b.first;
	}
}

void query1() {												// 1. �߰����� ���: Ư�� ���ð� ���Ե� ���Ḯ��Ʈ�� ���� ���� �ľ�
	int v, k, count = 0;
	cin >> v >> k;
	int headNum = getHeadNum(v);
	int size = cities[headNum].size();

	if (size <= k) {										// ����Ʈ�� k��° ���Ұ� ���� ��	
		cout << "no exist" << "\n";
		return;
	}

	list<city>::iterator iter = cities[headNum].begin();;	// iterator�� ����Ʈ���� ã�� �� ���
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

void query2() {								// 2. �߰����� ��� : Ư�� ���ð� ���Ե� ���Ḯ��Ʈ�� ũ��
	int v;
	cin >> v;

	int headNum = getHeadNum(v);			// head ����Ʈ�� ������ ���
	cout << cities[headNum].size() << "\n";
}

void query3() {								// 3. �߰��ܰ�: Kruskal �˰��򿡼� �ϳ��� �ݺ�(iteration) ����
	int v1 = path[E].second.first;			// ������ ���嵵�� ���� �߿��� ���� ���� ������ ������ ��������,
	int v2 = path[E].second.second;			// ���� ���Ϳ� �����ϱ����� ���� E�� �� ����
	int pathLen = path[E].first;
	E++;

	int h1 = getHeadNum(v1);				// ������ ������ �� ������ head�� ã���ְ�, ���� ���ٸ� ���� �����̹Ƿ� return
	int h2 = getHeadNum(v2);
	if (h1 == h2) {
		cout << "not union\n";
		return;
	}

	int lead, sub;							// weighted-union heuristic ���� ���ǹ�
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

	cities[lead].begin()->total += pathLen;	// query5��. ������ ���� ���̸� �����ش�.
	int newSize = _union(lead, sub);		// union
	mstPath.push_back(make_pair(pathLen, make_pair(v1, v2)));	// union�� �����ϸ� MST�� �־��ش�.

	int size = cities[lead].size();			// ������ ����Ʈ�� ����� ������ ���� ���ٸ� MST �ϼ�, MST ������ �Բ� return
	if (size == N) {
		int len = getLength();
		cout << lead << " " << newSize << " " << lead << " " << len << "\n";
		finish = true;
		return;
	}

	cout << lead << " " << newSize << "\n";	// MST�� �ϼ����� �ʾҴٸ� ������ ���� return
	return;
}

void query4() {							// 4. �߰����� ���: �� ���ð� ���� ���տ� ���ϴ��� Ȯ��
	int V1, V2;	
	cin >> V1 >> V2;
	int h1 = getHeadNum(V1);
	int h2 = getHeadNum(V2);

	if (h1 == h2) {						// �� ������ head�� ��
		cout << "True " << h1 << "\n";
	}
	else {
		cout << "False " << h1 << " " << h2 << "\n";
	}
}

void query5() {									// 5. �߰����� ��� : ������ ���ø� �����ϴ� ������ ��� ���嵵���� ����
	int v, pathLen = 0;
	cin >> v;

	int h = getHeadNum(v);

	cout << cities[h].begin()->total << "\n";	// head�� total �� ���
}

void query6() {								// 6. �˰����� ������ �ܰ� ���Ӽ��� �� ���α׷� ����
	int v1, v2, pathLen, h1, h2, lead, sub;

	while (1) {								// MST�� �ϼ��� ������ union �۾� �ݺ�
		v1 = path[E].second.first;
		v2 = path[E].second.second;
		pathLen = path[E].first;
		E++;

		h1 = getHeadNum(v1);
		h2 = getHeadNum(v2);
		if (h1 == h2) {						// head ���ù�ȣ�� ���ٸ� cycle, union�� ���������ʰ� ���� ���η� �Ѿ��.
			continue;
		}												// ���� query3�� ����
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