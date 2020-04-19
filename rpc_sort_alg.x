struct ascii_chars{
	int buf[40];
	int n;
};


program SORT_PRG{
	version SORT_VER{
		ascii_chars bubble_sort(ascii_chars)=1;
		ascii_chars merge_sort(ascii_chars)=2;
	}=1;
}=0x23451111;