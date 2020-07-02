#pragma once
//********************************************
// char* title = "Comparator"
// made by Lieman at 2020.07.02
//
// description:
//	Comparator
//********************************************





int ascendingOrderComparator_equalIncluded_byte(void* plhs, void* prhs, int sizeOfElement) {
	unsigned char lhs = *(unsigned char*)plhs;
	unsigned char rhs = *(unsigned char*)prhs;

	for (int i = 7; i >= 0; --i) {
		if (lhs >> i ^ rhs >> i) {
			if (lhs >> i & 0x01) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 1;
}

int ascendingOrderComparator_byte(void* plhs, void* prhs, int sizeOfElement) {
	unsigned char lhs = *(unsigned char*)plhs;
	unsigned char rhs = *(unsigned char*)prhs;

	for (int i = 7; i >= 0; --i) {
		if (lhs >> i ^ rhs >> i) {
			if (lhs >> i & 0x01) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 0;
}

int descendingOrderComparator_equalIncluded_byte(void* plhs, void* prhs, int sizeOfElement) {
	unsigned char lhs = *(unsigned char*)plhs;
	unsigned char rhs = *(unsigned char*)prhs;

	for (int i = 7; i >= 0; --i) {
		if (lhs >> i ^ rhs >> i) {
			if (rhs >> i & 0x01) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 1;
}

int descendingOrderComparator_byte(void* plhs, void* prhs, int sizeOfElement) {
	unsigned char lhs = *(unsigned char*)plhs;
	unsigned char rhs = *(unsigned char*)prhs;

	for (int i = 7; i >= 0; --i) {
		if (lhs >> i ^ rhs >> i) {
			if (rhs >> i & 0x01) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 0;
}

int ascendingOrderComparator_equalIncluded_int(void* plhs, void* prhs) {
	return *(int*)plhs <= *(int*)prhs;
}

int ascendingOrderComparator_int(void* plhs, void* prhs) {
	return *(int*)plhs < *(int*)prhs;
}

int descendingOrderComparator_equalIncluded_int(void* plhs, void* prhs) {
	return *(int*)plhs >= *(int*)prhs;
}

int descendingOrderComparator_int(void* plhs, void* prhs) {
	return *(int*)plhs > *(int*)prhs;
}

int isEqualTo_byte(void* plhs, void* prhs, int sizeOfElement) {
	unsigned char *lhs = (unsigned char*)plhs;
	unsigned char *rhs = (unsigned char*)prhs;

	int result = 0;

	for (int i = 0; i < sizeOfElement; ++i) {
		result |= lhs[i] ^ rhs[i];
	}

	return !result;
}