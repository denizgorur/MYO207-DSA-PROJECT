#include <stdio.h>
#define N 10

// Deniz Görür
// 2420161046
// BTK Akademi Sertifika Bağlantısı
https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=0Koh8DgqZ2

void dizi_yazdir(int dizi[], int BOYUT) {
	int i;
	for (i = 0; i < BOYUT; i++) {
		printf("%3d", dizi[i]);
	}
	printf("\n");
}

void takas(int *ap, int *bp) {
	int gecici = *ap;
	*ap = *bp;
	*bp = gecici;
}

// kokteyl siralama

void kokteyl_sirala(int dizi[], int BOYUT) {
	int i;
	int takas_oldu = 1;          
	int bas_ind = 0;
	int son_ind = BOYUT - 1;
	int sayac = 0;             

	while (takas_oldu == 1) {
		// bastan sona
		takas_oldu = 0;
		for (i = bas_ind; i < son_ind; i++) {
			if (dizi[i] > dizi[i + 1]) {
				takas(dizi + i, dizi + i + 1);
				takas_oldu = 1;
			}
		}
		if (takas_oldu == 0) {
			break;
		}
		son_ind--;

		// sondan basa
		takas_oldu = 0;
		for (i = son_ind - 1; i >= bas_ind; i--) {
			if (dizi[i] > dizi[i + 1]) {
				takas(dizi + i, dizi + i + 1);
				takas_oldu = 1;
			}
		}
		bas_ind++;

		printf("iter.%2d: ", ++sayac);
		dizi_yazdir(dizi, BOYUT);
	}
}

// ikili arama
int ikili_arama(int dizi[], int BOYUT, int search, int ilk_ind, int son_ind) {
	int orta_ind = (ilk_ind + son_ind) / 2;

	if (search == dizi[orta_ind]) {
		return orta_ind;
	}
	else if (search > dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
		return ikili_arama(dizi, BOYUT, search, orta_ind + 1, son_ind);
	}
	else if (search < dizi[orta_ind] && (son_ind - ilk_ind) > 0) {
		return ikili_arama(dizi, BOYUT, search, ilk_ind, orta_ind - 1);
	}
	else {
		return -1;
	}
}

int main() {
	int A[N] = {12, 3, 58, 26, 7, 49, 103, 95, 63, 2};
	int aranan, sonuc;

	printf("Orijinal dizi:\n");
	dizi_yazdir(A, N);

	kokteyl_sirala(A, N);

	printf("Siralanmis dizi:\n");
	dizi_yazdir(A, N);

	printf("Aranacak sayi: ");
	scanf("%d", &aranan);

	sonuc = ikili_arama(A, N, aranan, 0, N - 1);

	if (sonuc == -1) {
		printf("Aradiginiz deger %d dizide bulunamadi.\n", aranan);
	}
	else {
		printf("Aradiginiz deger %d dizinin %d. indisinde bulundu.\n", aranan, sonuc);
	}

	return 0;
}
