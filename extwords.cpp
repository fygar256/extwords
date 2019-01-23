/*
  英和、英英辞書ファイルから、
  単語ファイルを抽出するプログラム
*/
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<ctype.h>
#include	<iostream>
#include	<algorithm>
#include	<vector>
#include	<string>

using namespace std;

char *getword(FILE *fp,char *w) {
	int idx;
	int c;

  while(1) {
	idx=0;
	c=fgetc(fp);
  if (c==EOF) return(NULL);
	if (c==0x81) fgetc(fp);
		else ungetc(c,fp);

	while(1) {
		c=fgetc(fp);
    if (!isalpha(c)) {
        w[idx]='\0';
        while(fgetc(fp)!='\n'); 
        if (w[0]=='\0') break;
        return(w);
        }
    w[idx++]=c;
    }
  }
}

int	main(int argc,char *argv[])
{
	FILE	*fp;
	char	w[1000];
  vector<string> data;
	string	str;

	if (argc!=2) {
      fprintf(stderr,"Usage: words dicfile\n");
      exit(1);
      }

	fp=fopen(argv[1],"r");
	if (fp==NULL) exit(1);

	data.clear();
	while(1) {
      if (getword(fp,w)==NULL) break;
			str=w;
			for(auto & c:str) c=tolower(c);
			data.push_back(str); 
		}
	fclose(fp);

  sort(data.begin(), data.end());
  data.erase(unique(data.begin(), data.end()), data.end());

	for(auto i:data)
		cout << i <<endl;
	exit(0);
}
