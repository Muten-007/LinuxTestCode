#include<iostream>
using namespace std;
void DFS(int step);
int n;
int a[1000] ;//��ȫ���н���浽��������� 
int book[1000];        // ��� ������¼��I�����Ƿ��Ѿ���ʹ��  �����ʹ�� book[i]=1 ���� Ϊ0 
 

 
//step �ǵڼ����������  N�������߽� 
void DFS(int step){
	if(step==n+1){ //ѭ��������1��ʼ ���Ա߽��ǵ�N+1������	
		for(int i=1;i<=n;i++){
			cout<<a[i];
		}
		cout<<endl;//������� 
		return ;
	}else{
		//���ҿ���ʹ�õ�Ԫ�� 
		for(int i=1;i<=n;i++){ //��0��ʼ���� 
			
			if(book[i]==0){//�ж�Ԫ���Ƿ�ʹ�ù� 
				a[step]=i;  //Ԫ��û��ʹ�ù� ��������� 
				book[i]=1;  //������Ѿ���ʹ�� 
				DFS(step+1); //��ǰ����һ��
				book[i]=0; //������ɳ���֮ǰ�ı�� 
			}
		} 
		return ; //�ڱ�����ɺ��ٷ��ص� Book[i]=0 �Ӷ�ʵ�ֳ����������һص���һ�� 
	}
}

int main(void){
	cin>>n; //N������ȫ����

	DFS(1); 
	system("pause");
	return 0;
} 
