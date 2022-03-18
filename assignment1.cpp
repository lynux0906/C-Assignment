#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

//khai bao lop san pham
class sanpham{
	private:
		string masp; //Ma san pham
		string tensp; //Ten san pham
		int soluong; // So luong
		int dongia; // Don Gia 
	public:
		void nhap();
		void xuat();
		int getsoluong();
		int getdongia();
};

class phieu{
	private:
		string maphieu; //Ma phieu
		string mancc; //Ma Nha cung cap
		string diachi; //Dia chi
		string ngaylap; // Ngay lap
		string ncc; //Nha cung cap
		string sdt; // so dien thoai
	 	sanpham *sp;
		int n; // so luong san pham
		long tong;
	public:
		void nhap();
		void xuat();
		void soluong80();
		void tangdan();

};

void sanpham::nhap(){
	cout << "Nhap ma san pham: "; getline(cin, masp);
	cout << "Nhap ten san pham: "; getline(cin, tensp);
	cout << "Nhap so luong: "; cin >> soluong;
	cout << "Nhap don gia: "; cin >> dongia;
	cin.ignore();
}

void sanpham::xuat(){
	cout << setw(10) << masp << setw(20) << tensp << setw(10) << soluong << setw(10) << dongia << setw(15) << soluong*dongia << endl;
}

int sanpham::getsoluong(){
	return soluong;
}

int sanpham::getdongia(){
	return dongia;
}

void phieu::nhap(){
	cout << "Nhap ma phieu: "; getline(cin, maphieu);
	cout << "Nhap ma nha cung cap: "; getline(cin, mancc);
	cout << "Nhap dia chi: "; getline(cin, diachi);
	cout << "Nhap ngay lap: "; getline(cin, ngaylap);
	cout << "Nhap nha cung cap: "; getline(cin, ncc);
	cout << "Nhap so dien thoai: "; getline(cin, sdt);
	do{
		cout << "Nhap so san pham: "; cin >> n;
		cin.ignore();
	}while(n<=0);
	sp = new sanpham[n];
	for(int i = 0; i < n; i++){
		cout << "Nhap san pham thu " << i+1 << endl;
		sp[i].nhap();
	}
}

void phieu::xuat(){
	cout << "Dai hoc Victory" << endl;
	cout << setw(30) << "PHIEU NHAP VAN PHONG PHAM" << endl; 
	cout << "Ma Phieu: " << maphieu << endl;
	cout << "Ma nha cung cap: " << mancc << endl;
	cout << "Dia Chi: " << diachi << endl;
	cout << "Ngay Lap: " << ngaylap << endl;
	cout << "Ten nha cung cap: " << ncc << endl;
	cout << "SDT: " << sdt << endl;
	cout << setw(10) << "Ma SP" << setw(20) << "Ten Sp" << setw(10) << "So luong" << setw(10) << "Don gia" << setw(15) << "Thanh tien"<< endl;
	tong  = 0;
	for(int i = 0; i < n; i++){
		tong += sp[i].getdongia() * sp[i].getsoluong();
		sp[i].xuat();
	}
	cout << setw(50) << "Tong" << setw(15) << tong << endl;
}

void phieu::soluong80(){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(sp[i].getsoluong() < 80){
			count++;
		}
	}
	cout << "So san pham co so luong nho hon 80: " << count << endl;
}
int main(){
	phieu p;
	p.nhap();
	cout << "Phieu chua sap xep" << endl;
	p.xuat();

	p.soluong80();
	return 0;
}
