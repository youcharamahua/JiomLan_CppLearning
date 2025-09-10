#include <bits/stdc++.h>
using namespace std;

/*
��ʹ��˫���б��ģ������ 
#include <bits/stdc++.h>
using namespace std;

int nextL[1000005];
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
		nextL[i]=i+1;
	}
	nextL[n]=1;//����ѭ��
	 
	int p=0;
	for(int i=1;i<=n;i++){ //ÿһ��ǹ��һ���ˣ�ǹ��ʮ�ξ͹��� 
		for(int j=1;j<m;j++){
			p=nextL[p];
		}
		cout<<p[nextL]<<" ";
		nextL[p]=nextL[nextL[p]];
	}
	return 0;
	
}
*/

//double linked list ˫���б� 
struct DLList{
	int data;
	DLList *prev; //ָ��ǰһ���ڵ��ָ�� 
	DLList *next; //ָ���һ���ڵ��ָ�� 
	
	// �ڴ����½ڵ�ʱ��ʼ��
    Node(int val) {
        data = val;      // ��������
        prev = nullptr;  // ǰָ����Ϊ��
        next = nullptr;  // ��ָ����Ϊ��
    }
    /* ���캯����Node(int val) : data(val), prev(nullptr), next(nullptr) {}
	����˵����(: ð�ű�ʾ�����ǳ�ʼ���б�)
     - val: Ҫ�洢�ı��
     - prev: ��ʼ��Ϊnullptr����ָ�룩����ʾ��û��ǰ���ڵ�
     - next: ��ʼ��Ϊnullptr����ָ�룩����ʾ��û�к�̽ڵ�
     �յĴ����ű�ʾ�������ǿյģ�û������������Ҫִ��
    */ 
};

int n,m;
int main(){
	cin>>n>>m;
	DLList *head = new DLList(1);// ��������ĵ�һ���ڵ㣨���Ϊ1���ˣ�
	/*
	new �ľ�������
	Node* head = new DLList(1);
	���д������������£�
	�����ڴ棺�ڶѣ�heap���Ϸ����㹻�洢һ�� DLList ������ڴ�ռ�
	���ù��캯�������� Node ��Ĺ��캯������ʼ������ڴ�ռ�
	����ָ�룺��������ڴ�ռ�ĵ�ַ���������ͨ��ָ�������
     - new Node(1): ���ڴ��з���ռ䴴��һ���½ڵ㣬���Ϊ1
     - Node* head: ����һ��ָ�����head��ָ������´����Ľڵ�
	*/
	DLList *current = head;  // ����һ����ǰָ�룬��ʼָ��ͷ�ڵ�
	
	for(int i = 2; i <= n; i++){
		DLList *newNode = new DLList(i);
		
		// ����ǰ�ڵ��nextָ��ָ���½ڵ�
		current->next = newNode;
        // ���ͣ�
        // - current->next: ����currentָ��Ľڵ��next��Ա
        // - ���½ڵ�ĵ�ַ��ֵ��current->next
        
        // ���½ڵ��prevָ��ָ��ǰ�ڵ�
        newNode->prev = current;
        
        // ����ǰָ���ƶ����´����Ľڵ㣬Ϊ��һ��ѭ����׼��
        current = newNode;
	}
	
	// ��������β���ӣ��γ�ѭ������
    current->next = head;  // ���һ���ڵ��nextָ��ͷ�ڵ�
    head->prev = current;  // ͷ�ڵ��prevָ�����һ���ڵ�
    
    // ����������һ��˫��ѭ������������Χ��һȦ
    
    current = head;  // �ӵ�һ���˿�ʼ����
    
    // ��������δ��Ȧʱ����ѭ��
    while (n > 0) {
        // ��m-1���ˣ���Ϊ�ӵ�ǰ�ڵ㿪ʼ��������ֻ��Ҫ��m-1�Σ�
        for (int i = 1; i < m; i++) {
            current = current->next;  // �ƶ�����һ���ڵ�
        }
        
        // ��ǰ�ڵ����Ҫ��Ȧ����
        Node *toDelete = current;  // ����Ҫɾ���Ľڵ��ָ��
        
        // �����Ȧ�˵ı��
        cout << toDelete->data << " ";
        
        // ����ǰָ���ƶ�����һ���ڵ㣬Ϊ��һ�α�����׼��
        current = current->next;
        
        // ��������ָ�룬�Ƴ�Ҫɾ���Ľڵ�
        toDelete->prev->next = toDelete->next;  // ǰһ���ڵ��nextָ���һ���ڵ�
        toDelete->next->prev = toDelete->prev;  // ��һ���ڵ��prevָ��ǰһ���ڵ�
        
        // �ͷű�ɾ���ڵ���ڴ�
        delete toDelete;
        
        n--;  // ʣ��������һ
    }
	return 0;
} 
