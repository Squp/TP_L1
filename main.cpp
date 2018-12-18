#include "Transite.hpp"
#include <fstream>
#include <iomanip>

using namespace std;


int main(){
   setlocale(LC_ALL, "");
   Transite tr;
   Car ct;
   Airplane ap;
   Train tra;
   ifstream in;
   ofstream out;
   int ch1, ch2, n;
   while(true){
		cout << "\n\n1. Добавить\n2. Удалить\n3. Изменить\n4. Сохранить\n5. Загрузить\n6. Вывести\n7. Выход\n";
		while(!(cin >> ch1) && ch1 > 0 && ch1 < 7);
		if(ch1 == 7) return 0;
		cout << "1. Машина\n2. Самолёт\n3. Поезд\n";
		while(!(cin >> ch2) && ch2 > 0 && ch2 < 4);
		switch(ch1){
		case 1:
			try{
			   switch(ch2){
			   case 1:
				   cout << "Время объём города год модель марка\n";
				   cin >> ct;
				   tr.car().add(ct);
				   break;
			   case 2:
				   cout << "Наименование города объёмы габариты тип\n";
				   cin >> ap;
				   tr.airplane().add(ap);
				   break;
			   case 3:
				   cout << "Наименование города объёмы год вагоны\n";
				   cin >> tra;
				   tr.train().add(tra);
				   break;
			   }
			}
			catch(const Exception& exc){
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    cin.clear();
			    cin.sync();
				cout << exc.what();
			}
			break;
		case 2:
			cout << "Индекс\n";
			switch(ch2){
			   case 1:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < tr.car().size());
				   tr.car().remove(ch1);
				   break;
			   case 2:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < tr.airplane().size());
				   tr.airplane().remove(ch1);
				   break;
			   case 3:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < tr.train().size());
				   tr.train().remove(ch1);
				   break;
			   }
			break;
		case 3:
			try{
			   cout << "Индекс\n";
			   switch(ch2){
			   case 1:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < tr.car().size());
				   cout << "Время объём города год модель марка\n";
				   cin >> tr.car()[ch1];
				   break;
			   case 2:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < tr.airplane().size());
				   cout << "Наименование города объёмы габариты тип\n";
				   cin >> tr.airplane()[ch1];
				   break;
			   case 3:
				   while(!(cin >> ch1) && ch1 >= 0 && ch1 < tr.train().size());
				   cout << "Наименование города объёмы год вагоны\n";
				   cin >> tr.train()[ch1];
				   break;
			   }
			}
			catch(const Exception& exc){
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    cin.clear();
			    cin.sync();
				cout << exc.what();
			}
			break;
		case 4:
			switch(ch2){
			   case 1:
				   out.open("car");
				   out << tr.car().size() << '\n';
				   for(int i = 0; i < tr.car().size(); ++i)
						out << tr.car()[i] << '\n';
				   break;
			   case 2:
				   out.open("ap");
				   out << tr.airplane().size() << '\n';
				   for(int i = 0; i < tr.airplane().size(); ++i)
						out << tr.airplane()[i] << '\n';
				   break;
			   case 3:
				   out.open("tra");
				   out << tr.train().size() << '\n';
				   for(int i = 0; i < tr.train().size(); ++i)
						out << tr.train()[i] << '\n';
				   break;
			   }
			out.close();
			break;
		case 5:
			try{
			   switch(ch2){
			   case 1:
				   in.open("car");
				   in >> n;
				   for(int i = 0; i < n; ++i){
					   in >> ct;
					   tr.car().add(ct);
				   }
				   break;
			   case 2:
				   in.open("ap");
				   in >> n;
				   for(int i = 0; i < n; ++i){
					   in >> ap;
					   tr.airplane().add(ap);
				   }
				   break;
			   case 3:
				   in.open("tra");
				   in >> n;
				   for(int i = 0; i < n; ++i){
					   in >> tra;
					   tr.train().add(tra);
				   }
				   break;
			   }
			}
			catch(const Exception& exc){
				cout << exc.what();
			}
			in.close();
			break;
		case 6:			    
			cout << setw(2) << "№" << setw(10) << "Наим." << setw(10) << "города" << setw(10) << "объёмы";
			switch(ch2){
			   case 1:
				   cout<< setw(10) << "время" << setw(12) << "год"<< setw(12) << "марка";		   
				   for(int i = 0; i < tr.car().size(); ++i)
						cout << '\n' << setw(2) << i 
						<< setw(10)  << tr.car()[i].name()
						<< setw(10)  << tr.car()[i].citirs()
						<< setw(10)  << tr.car()[i].volume()
						<< setw(10)  << tr.car()[i].times()
						<< setw(12)  << tr.car()[i].year()
				        << setw(12)  << tr.car()[i].mark();
				   break;
			   case 2:
				   cout<< setw(10) << "габариты" << setw(10) << "тип";
				   for(int i = 0; i < tr.airplane().size(); ++i)
						cout << '\n' << setw(2) << i 
						<< setw(10)  << tr.airplane()[i].name()
						<< setw(10)  << tr.airplane()[i].citirs()
						<< setw(10)  << tr.airplane()[i].volume()
						<< setw(10)  << tr.airplane()[i].size()
						<< setw(12)  << tr.airplane()[i].type();
				   break;
			   case 3:
				   cout<< setw(10) << "год" << setw(10) << "вагоны";
				   for(int i = 0; i < tr.train().size(); ++i)
						cout << '\n' << setw(2) << i 
						<< setw(10)  << tr.train()[i].name()
						<< setw(10)  << tr.train()[i].citirs()
						<< setw(10)  << tr.train()[i].volume()
						<< setw(10)  << tr.train()[i].year()
						<< setw(12)  << tr.train()[i].cnt();
				   break;
			   }
			break;
		}
   }
}

