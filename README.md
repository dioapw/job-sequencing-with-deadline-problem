# Job Sequencing With Deadline Problem
Algorithm Series: Job Sequencing With Deadline Problem - Greedy Method

## Deskripsi Persoalan:

- Ada n buah pekerjaan yang akan dikerjakan oleh sebuah mesin
- Tiap pekerjaan diproses oleh mesin selama 1 satuan waktu dan tenggat waktu ( deadline ) 
<br/> pengerjaan setiap pekerjaan i adalah d<sub>i</sub> >= 0.
- Pekerjaan i akan memberikan keuntungan sebesar p subscript i jika dan hanya jika pekerjaan tersebut diselesaikan tidak melebihi tenggat waktunya
- Bagaimana memilih perkerjaan-pekerjaan yang akan dikerjakan oleh mesin sehingga keuntungan yang diperoleh dari pengerjaan itu maksimum?
Contoh:

Misalkan terdapat 4 pekerjaan ( n = 4 ): 
<br/>
![image](https://user-images.githubusercontent.com/55073908/111078526-7307a900-8528-11eb-83a6-ff71ad4f8ae4.png)
<br/>
![image](https://user-images.githubusercontent.com/55073908/111078546-992d4900-8528-11eb-84d6-46d147f94521.png)



Andaikan mesin mulai bekerja jam 6.00 pagi , maka itu artinya:
<br/>
![image](https://user-images.githubusercontent.com/55073908/111078471-24f2a580-8528-11eb-9b58-b4547530508c.png)




## Strategi Penyelesaian
1) Sorting pekerjaan berdasarkan nilai profit secara descending.
2) total perkerjaan yang tersedia menjadi total slot tersedia karena setiap perkerjaan adalah 1 unit waktu.
3) lakukan iterasi untuk setiap perkerjaan dari pekerjaan pertama dan bandingkan nilai deadline dengan slot waktu yang tersedia.
4) jika dealine lebih besar dari slot waktu maka perkerjaan tidak diambil.
5) jika dealine lebih kecil sama dengan dari slot waktu dan slot tersedia maka, masukkan pekerjaan kedalam slot sesuai waktu deadlinenya dan tutup slot yang digunakan itu.
6) jika slot penuh maka cek slot dengan nilai yang lebih rendah dari nilai deadline apakah ada slot kosong ( lakukan iterasi mundur).
7) jika ada, maka masukkan pekerjaan kedalam slot dan tutup slot yang digunakan itu.
8) jika tidak ada maka perkerjaan tidak dilakukan.


## Pseudocode
```
function penjadwalan (pekerjaan slot[], int jumlahSlot)
{
  sort (slot, jumlahSlot);

  int hasil[jumlahSlot];
  bool slotTersedia[jumlahSlot];

  for (int i = 0; i < jumlahSlot; i++)
  {
          for (int j = minimum (jumlahSlot, slot[i].tenggatWaktu); j >= 0; j--)
    	    {
              if (slotTersedia[j] == true)
                {
                  hasil[j] = i;
                  slotTersedia[j] = false;
                }
    	    }
   }
}
```


## Kompleksitas Waktu
- O(n<sup>2</sup>)

<br/>

## Video Penjelasan
[![](http://img.youtube.com/vi/zPtI8q9gvX8/0.jpg)](http://www.youtube.com/watch?v=zPtI8q9gvX8 "Job Sequencing with Deadlines - Greedy Method")


<br/>

## Referensi
- https://www.geeksforgeeks.org/job-sequencing-problem/
- https://www.youtube.com/watch?v=zPtI8q9gvX8
