	int n; cin >> n;
	int arr[1005], brr[1005];

	rep(i, 0, n) {
		cin >> arr[i];
	}

	// coordinate compression
	iota(brr, brr + n, 0);
	sort(brr, brr + n, [&](int i, int j) -> bool {
		if (arr[i] != arr[j]) return arr[i] < arr[j];
		else return i < j;
		});
	rep(i, 0, n) arr[brr[i]] = i;
