// 研究public protected private
#include <iostream>

using namespace std;

class base{
	public:
		void base_public(){cout<<"This is base_public;"<<endl;}
	protected:
		void base_protected(){cout<<"This is base_protected;"<<endl;}
	private:
		void base_private(){cout<<"This is base_private;"<<endl;}
};

class derived_public: public base{
	public:
		void visit_base_protected(){
			cout<<"This is visit_base_protected in derived_public;"<<endl;
			base_protected();
		}
};

class derived_protected: protected base{
	public:
		void visit_base_protected(){
			cout<<"This is visit_base_protected in derived_protected;"<<endl;
			base_protected();
		}
};

class derived_private: private base{
	public:
		void visit_base_protected(){
			cout<<"This is visit_base_protected in derived_private;"<<endl;
			base_protected();
			// compile error
			// base_private();		
		}
};

class derived_derived_private: public derived_private{
	public:
		void dd_visit_base_protected(){
			cout<<"This is dd_visit_base_protected in derived_derived_private;"<<endl;
			// complie error
			// base_protected();
		}
};

int main(void){
	derived_public de_public;
	derived_protected de_protected;
	derived_private de_private;	
	de_public.visit_base_protected();
	de_protected.visit_base_protected();
	de_private.visit_base_protected();

	// test visit pulbic member functions
	cout << "----- visit public member functions -----" << endl;
	de_public.base_public();
	// compile error
	// de_protected.base_public();
	
	derived_derived_private dd_private;
	dd_private.dd_visit_base_protected();
}
