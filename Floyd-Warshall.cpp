	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) map[i][j] = INF;//cost from A to A is 0.
		}
	for (int k = 0; k < n; k++)
		for (int j = 0; j < n; j++)
			for (int i = 0; i < n; i++)
				map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
