//inspired by https://www.geeksforgeeks.org/job-sequencing-problem/

#include <iostream>
#include <algorithm>

using namespace std;

struct pekerjaan
{
  char id;
  int tenggatWaktu;
  int keuntungan;
};

bool perbandingan (pekerjaan a, pekerjaan b)
{
  return (a.keuntungan > b.keuntungan);
}

void print (pekerjaan slot[], int hasil[], bool slotTersedia[], int jumlahSlot)
{
  for (int i = 0; i < jumlahSlot; i++)
    {
        if (slotTersedia[i] == false && slotTersedia[i + 1] == false)
    	{
    	    cout << slot[hasil[i]].id << ',';
    	} else if (slotTersedia[i] == false && slotTersedia[i + 1] == true) {
    	    cout << slot[hasil[i]].id;
    	}
    }
}

void penjadwalan (pekerjaan slot[], int jumlahSlot)
{
  sort (slot, slot + jumlahSlot, perbandingan);

  int hasil[jumlahSlot];
  bool slotTersedia[jumlahSlot];

  for (int i = 0; i < jumlahSlot; i++)
    {
      slotTersedia[i] = true;
    }

  for (int i = 0; i < jumlahSlot; i++)
    {
          for (int j = min (jumlahSlot, slot[i].tenggatWaktu) - 1; j >= 0; j--)
    	{
        	  if (slotTersedia[j] == true)
        	    {
        	      hasil[j] = i;
        	      slotTersedia[j] = false;
        	      break;
        	    }
    	}
    }
    print (slot, hasil, slotTersedia, jumlahSlot);
}


int main ()
{
  cout << "Masukkan jumlah pekerjaan yang ada: ";
  int n;
  cin >> n;
  
  cout << endl;
  
  pekerjaan slot[n];
  int jumlahSlot = sizeof (slot) / sizeof (slot[0]);
  
  for (int i = 0; i < jumlahSlot; i++)
    {
      cout << "Masukkan id, tenggat waktu dan keuntungan pekerjaan: ";
      cin >> slot[i].id >> slot[i].tenggatWaktu >> slot[i].keuntungan;
      cout << endl;
    }
    
  cout <<"Urutan perkerjaan-pekerjaan yang akan dikerjakan sehingga memiliki keuntungan maksimum\n";
  penjadwalan (slot, jumlahSlot);
  
  return 0;
}
