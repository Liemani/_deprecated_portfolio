int ascendingOrderComparator_equalIncluded_Byte(void* lhs, void* rhs, int sizeOfElement) {
	unsigned char plhs = *(unsigned char*)lhs;
	unsigned char prhs = *(unsigned char*)rhs;

	for (int i = 7; i >= 0; --i) {
		if (plhs >> i ^ prhs >> i) {
			if (plhs >> i & 0x01) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 1;
}

int ascendingOrderComparator_Byte(void* lhs, void* rhs, int sizeOfElement) {
	unsigned char plhs = *(unsigned char*)lhs;
	unsigned char prhs = *(unsigned char*)rhs;

	for (int i = 7; i >= 0; --i) {
		if (plhs >> i ^ prhs >> i) {
			if (plhs >> i & 0x01) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 0;
}

int descendingOrderComparator_equalIncluded_Byte(void* lhs, void* rhs, int sizeOfElement) {
	unsigned char plhs = *(unsigned char*)lhs;
	unsigned char prhs = *(unsigned char*)rhs;

	for (int i = 7; i >= 0; --i) {
		if (plhs >> i ^ prhs >> i) {
			if (prhs >> i & 0x01) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 1;
}

int descendingOrderComparator_Byte(void* lhs, void* rhs, int sizeOfElement) {
	unsigned char plhs = *(unsigned char*)lhs;
	unsigned char prhs = *(unsigned char*)rhs;

	for (int i = 7; i >= 0; --i) {
		if (plhs >> i ^ prhs >> i) {
			if (prhs >> i & 0x01) {
				return 0;
			} else {
				return 1;
			}
		}
	}
	return 0;
}