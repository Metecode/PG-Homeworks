# PG-Homeworks Proje 1 rapor
PROJE AMACI:
Bilgisayar ürünlerinin kaydını alan, silen, güncelleyen ve listeleyen aynı şekilde müşteri ve satış kayıtlarını dosyalamasını yapan temel satış yazılımı.
YAPTIKLARIM:
Projeye başlarken ilk olarak gerekli fonksiyonları kütüphaneleri ekledim. Her işlem için ayrı bir void fonksiyonu ve ayrı birer class oluşturdum. Class kullanmamdaki amaç her işlem için ayrı bir değişken oluşturmamak. Ürün, firma ve siparişler için ayrı ayrı bool kontrol fonksiyonları oluşturdum. Bu yapmamdaki amaç kullanıcı hatasında (mesela kayıtlı bir ürün kodu girilmezse) hem kullanıcıyı bilgilendirmek ve kodun stabil ve düzgün çalışmasını sağlamak hem de ürün kodu ve firma no girilirken bu değerlerin tekil olmasını sağlamak (Böylece aynı ürün kodu bir daha kullanılamaz).
Switch caseler ile menüleri oluşturdum.  Ardından sipariş işlemleri kısmına geçtim ürün ekleme kısmında ürün ismi, kodu, üreticisi, temin süresi, Üretim tarihi , Fiyat , özel müşteriler için fiyatı , kdv oranı, stok sayısını ekledim. Diğer işlemler ise ürün arama, listeleme, düzenleme, silme.
Ürün.txt okurken ve yazdırırken txt dosyasının düzeni ise şöyle:

Product.txt     // urun.txt

Ürün kodu (string)

Ürün ismi (string)

Üretici ismi (string)

Temin süresi (string)

Üretim tarihi (string)

Fiyat (genel müşteriler için) (float)

Özel fiyat (özel müşteriler için) (float)

KDV (int)

Stok sayış (int)


Müşteri kısmında firma no(tekil), ismi, telefonu , sorumlusu, kategorisi (özel ve genel şeklinde 2 kategoriye ayırdım) ve son olarak adresi aldım. Müşteri.txt dosyasına müşteri yazdırırken ve okurken txt dosyasının düzeni:

Customer.txt   // cari.txt

Firma no (string)

Firma ismi (string)

Firma telefon (string)

Firma sorumlusu (string)

Müşteri kategorisi(genel/özel) (string)
Adres (string)

Sipariş işlemlerinde 2 ayrı txt dosyası olarak sipariş txt ve sipariş listesi txt’i oluşturdum. Sipariş txt’e sipariş numarası oluşturdum bunu oluşturmamın sebebi sipariş txt ile sipariş listesi txt’i arasındaki iletişimi sağlayabilmek çünkü bir firma 1’den fazla farklı sipariş verebilir ve kullanıcı eğer bu siparişleri güncellemek istediğinde hangi siparişi düzenleyeceğini sadece firma no ile seçemez bu yüzden sipariş numarası adında yeni veri ekledim ve bu sipariş numarası sayesinde kullanıcı istediği siparişi güncelleyebilir. Sipariş numarası, sipariş girildiği zaman sistem rastgele oluşturur. Sipariş txt’e tutulan bilgiler: sipariş numarası, firma no, müşteri ismi, müşteri kategori, sipariş tutarı (Girilen kdv değerine göre tutara kdv dahildir), sipariş detaylarının tutulduğu dosyanın ismi ve siparişin verildiği tarih.
Sipariş txt dosyasına sipariş yazdırırken ve okurken txt dosyasının düzeni:


Order.txt // sipariş.txt

Sipariş numarası (Sistem random veriyor) (int)

Firma no 

Müşteri ismi

Müşteri kategori 

Sipariş tutarı (kdv dahil) (float)

Sipariş listesi dosyası (string)

Sipariş veriliş tarihi (string)


Son dosya olan sipariş listesi dosyasında ise sipariş numarası, ürün birim fiyatı, ürün kodu, adet sayısı, ürün ismi, kdv oranı.
Sipariş listesi dosyasına bilgi yazdırırken ve okurken txt dosyasının düzeni:


OrderList.txt // siparişlistesi.txt

Sipariş numarası 

Ürün birim fiyatı (float)

Ürün kodu 

Adet sayısı 

Ürün ismi

Kdv oranı

Ve ayrıca her siparişte stok sayısı güncellenir.
