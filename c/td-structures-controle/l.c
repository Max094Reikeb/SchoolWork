#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
	int a;
	int j;
	int h;
	int m;
	int s;
	system("clear");
	printf("Entrez les années : ");
	scanf("%d", &a);
	printf("Entrez les jours : ");
	scanf("%d", &j);
	printf("Entrez les heures : ");
	scanf("%d", &h);
	printf("Entrez les minutes : ");
	scanf("%d", &m);
	printf("Entrez les secondes : ");
	scanf("%d", &s);
	system("clear");
	if (a < 10) {
		if (j < 10) {
			if (h < 10) {
				if (m < 10) {
					if (s < 10) {
						printf("Compte à rebours : 0%d:0%d:0%d:0%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : 0%d:0%d:0%d:0%d:%d\n", a, j, h, m, s);
					}
				} else {
					if (s < 10) {
						printf("Compte à rebours : 0%d:0%d:0%d:%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : 0%d:0%d:0%d:%d:%d\n", a, j, h, m, s);
					}
				}
			} else {
				if (m < 10) {
					if (s < 10) {
						printf("Compte à rebours : 0%d:0%d:%d:0%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : 0%d:0%d:%d:0%d:%d\n", a, j, h, m, s);
					}
				} else {
					if (s < 10) {
						printf("Compte à rebours : 0%d:0%d:%d:%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : 0%d:0%d:%d:%d:%d\n", a, j, h, m, s);
					}
				}
			}
		} else {
			if (h < 10) {
				if (m < 10) {
					if (s < 10) {
						printf("Compte à rebours : 0%d:%d:0%d:0%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : 0%d:%d:0%d:0%d:%d\n", a, j, h, m, s);
					}
				} else {
					if (s < 10) {
						printf("Compte à rebours : 0%d:%d:0%d:%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : 0%d:%d:0%d:%d:%d\n", a, j, h, m, s);
					}
				}
			} else {
				if (m < 10) {
					if (s < 10) {
						printf("Compte à rebours : 0%d:%d:%d:0%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : 0%d:%d:%d:0%d:%d\n", a, j, h, m, s);
					}
				} else {
					if (s < 10) {
						printf("Compte à rebours : 0%d:%d:%d:%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : 0%d:%d:%d:%d:%d\n", a, j, h, m, s);
					}
				}
			}
		}
	} else {
		if (j < 10) {
			if (h < 10) {
				if (m < 10) {
					if (s < 10) {
						printf("Compte à rebours : %d:0%d:0%d:0%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : %d:0%d:0%d:0%d:%d\n", a, j, h, m, s);
					}
				} else {
					if (s < 10) {
						printf("Compte à rebours : %d:0%d:0%d:%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : %d:0%d:0%d:%d:%d\n", a, j, h, m, s);
					}
				}
			} else {
				if (m < 10) {
					if (s < 10) {
						printf("Compte à rebours : %d:0%d:%d:0%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : %d:0%d:%d:0%d:%d\n", a, j, h, m, s);
					}
				} else {
					if (s < 10) {
						printf("Compte à rebours : %d:0%d:%d:%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : %d:0%d:%d:%d:%d\n", a, j, h, m, s);
					}
				}
			}
		} else {
			if (h < 10) {
				if (m < 10) {
					if (s < 10) {
						printf("Compte à rebours : %d:%d:0%d:0%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : %d:%d:0%d:0%d:%d\n", a, j, h, m, s);
					}
				} else {
					if (s < 10) {
						printf("Compte à rebours : %d:%d:0%d:%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : %d:%d:0%d:%d:%d\n", a, j, h, m, s);
					}
				}
			} else {
				if (m < 10) {
					if (s < 10) {
						printf("Compte à rebours : %d:%d:%d:0%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : %d:%d:%d:0%d:%d\n", a, j, h, m, s);
					}
				} else {
					if (s < 10) {
						printf("Compte à rebours : %d:%d:%d:%d:0%d\n", a, j, h, m, s);
					} else {
						printf("Compte à rebours : %d:%d:%d:%d:%d\n", a, j, h, m, s);
					}
				}
			}
		}
	}
	while (j >= 0) {
		while (h >= 0) {
			while (m >= 0) {
				while (s > 0) {
					system("clear");
					if (a < 10) {
						if (j < 10) {
							if (h < 10) {
								if (m < 10) {
									if (s < 10) {
										printf("Compte à rebours : 0%d:0%d:0%d:0%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : 0%d:0%d:0%d:0%d:%d\n", a, j, h, m, s);
									}
								} else {
									if (s < 10) {
										printf("Compte à rebours : 0%d:0%d:0%d:%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : 0%d:0%d:0%d:%d:%d\n", a, j, h, m, s);
									}
								}
							} else {
								if (m < 10) {
									if (s < 10) {
										printf("Compte à rebours : 0%d:0%d:%d:0%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : 0%d:0%d:%d:0%d:%d\n", a, j, h, m, s);
									}
								} else {
									if (s < 10) {
										printf("Compte à rebours : 0%d:0%d:%d:%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : 0%d:0%d:%d:%d:%d\n", a, j, h, m, s);
									}
								}
							}
						} else {
							if (h < 10) {
								if (m < 10) {
									if (s < 10) {
										printf("Compte à rebours : 0%d:%d:0%d:0%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : 0%d:%d:0%d:0%d:%d\n", a, j, h, m, s);
									}
								} else {
									if (s < 10) {
										printf("Compte à rebours : 0%d:%d:0%d:%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : 0%d:%d:0%d:%d:%d\n", a, j, h, m, s);
									}
								}
							} else {
								if (m < 10) {
									if (s < 10) {
										printf("Compte à rebours : 0%d:%d:%d:0%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : 0%d:%d:%d:0%d:%d\n", a, j, h, m, s);
									}
								} else {
									if (s < 10) {
										printf("Compte à rebours : 0%d:%d:%d:%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : 0%d:%d:%d:%d:%d\n", a, j, h, m, s);
									}
								}
							}
						}
					} else {
						if (j < 10) {
							if (h < 10) {
								if (m < 10) {
									if (s < 10) {
										printf("Compte à rebours : %d:0%d:0%d:0%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : %d:0%d:0%d:0%d:%d\n", a, j, h, m, s);
									}
								} else {
									if (s < 10) {
										printf("Compte à rebours : %d:0%d:0%d:%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : %d:0%d:0%d:%d:%d\n", a, j, h, m, s);
									}
								}
							} else {
								if (m < 10) {
									if (s < 10) {
										printf("Compte à rebours : %d:0%d:%d:0%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : %d:0%d:%d:0%d:%d\n", a, j, h, m, s);
									}
								} else {
									if (s < 10) {
										printf("Compte à rebours : %d:0%d:%d:%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : %d:0%d:%d:%d:%d\n", a, j, h, m, s);
									}
								}
							}
						} else {
							if (h < 10) {
								if (m < 10) {
									if (s < 10) {
										printf("Compte à rebours : %d:%d:0%d:0%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : %d:%d:0%d:0%d:%d\n", a, j, h, m, s);
									}
								} else {
									if (s < 10) {
										printf("Compte à rebours : %d:%d:0%d:%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : %d:%d:0%d:%d:%d\n", a, j, h, m, s);
									}
								}
							} else {
								if (m < 10) {
									if (s < 10) {
										printf("Compte à rebours : %d:%d:%d:0%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : %d:%d:%d:0%d:%d\n", a, j, h, m, s);
									}
								} else {
									if (s < 10) {
										printf("Compte à rebours : %d:%d:%d:%d:0%d\n", a, j, h, m, s);
									} else {
										printf("Compte à rebours : %d:%d:%d:%d:%d\n", a, j, h, m, s);
									}
								}
							}
						}
					}
					sleep(1);
					s--;
				}
				s = 59;
				m--;
			}
			m = 59;
			h--;
		}
		h = 23;
		j--;
	}
	j = 364;
	j--;
	system("clear");
	printf("BOOM!\n");
}
