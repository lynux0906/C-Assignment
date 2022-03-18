#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class nguoi{
	protected:
		string hoten; //ten nguoi
		string ngaysinh; //ngay sinh
		string quequan; //que quan
	public:
		void nhap();
		void xuat();
};

class sinhvien : public nguoi{
	private:
		string masv; // khai bao ma sinh vien
		string nganh; // khai bao nganh
		int khoahoc; //khai bao khoa hoc
	public:
		void nhap();
		void xuat();
		int getkhoahoc();
};

class lophoc{
	private:
		string malh; // ma lop hoc
		string tenlh; //Ten Lop hoc
		string ngaymo; //ngay mo lop hoc
		sinhvien *x; //khai bao sinh vien
		int n; //so luong sinh vien
		string giaovien; // ten giao vien chu nhiem
	public:
		void nhap();
		void xuat();
		void khoa11();
		void sapxep();
};

void nguoi::nhap(){
	cout << "Nhap ho ten sinh vien: "; getline(cin, hoten);
	cout << "Nhap ngay sinh: "; getline(cin, ngaysinh);
	cout << "Nhap que quan: "; getline(cin, quequan);
}

void nguoi::xuat(){
	cout << setw(20) << hoten << setw(15) << ngaysinh << setw(20) << quequan;
}

void sinhvien::nhap(){
	nguoi::nhap();
	cout << "Nhap ma sinh vien: "; getline(cin, masv);
	cout << "Nhap nganh hoc: "; getline(cin, nganh);
	cout << "Nhap khoa hoc: "; cin >> khoahoc;
	cin.ignore();
}

void sinhvien::xuat(){
	nguoi::xuat();
	cout << setw(10) << masv << setw(15) << nganh << setw(10) << khoahoc << endl; 
}

int sinhvien::getkhoahoc(){
	return khoahoc;
}

void lophoc::nhap(){
	cout << "Nhap ma lop: "; getline(cin, malh);
	cout << "Nhap ten lop hoc: "; getline(cin, tenlh);
	cout << "Ngay mo: "; getline(cin, ngaymo);
	cout << "Nhap so sinh vien: "; cin >> n;
	cin.ignore();
	x = new sinhvien[n];
	for(int i = 0; i < n; i++){
		cout << "Nhap sinh vien " << i+1 << endl;
		x[i].nhap();
	}
	cout << "Nhap ten giao vien: "; getline(cin, giaovien);
}

void lophoc::xuat(){
	cout << "Ma lop hoc: " << malh << endl;
	cout << "Ten lop hoc: " << tenlh << endl;
	cout << "Ngay Mo: " << ngaymo << endl;
	cout << "Giao vien chu nhiem: " << giaovien << endl;
	cout << setw(20) << "Ho Ten" << setw(15) << "Ngay sinh" << setw(20) << "Que Quan";
	cout << setw(10) << "Ma SV" << setw(15) << "Nganh" << setw(10) << "Khoa" << endl;
	for(int i = 0; i < n; i++){
		x[i].xuat();
	}
}

void lophoc::khoa11(){
	int count = 0;
	for(int i = 0; i < n; i++){
		if(x[i].getkhoahoc() == 11){
			count++;
		}
	}
	cout << "So sinh vien khoa 11: " << count << endl;
}

int main(){

	lophoc lp;
	lp.nhap();
	cout << "======= Thong tin lop hoc ========" << endl;
	lp.xuat();

	lp.khoa11();
	return 0;
}
