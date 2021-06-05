/*************************************************************************/
/*								免責事項								 */
/*		このプログラムで起きたあらゆる損害に責任を持ちません。			 */
/*																		 */
/*																	   	 */
/*		作成者  霧紙 レイ、stender氏									 */
/*		作成日  2021/06/05												 */
/*																		 */
/*								その他									 */
/*		利用にあたってはご自由にどうぞ。								 */
/*		Twitterで一言いただけるとモチベが上がりアップデートするかも？	 */
/*																	   	 */
/*************************************************************************/


//使用したヘッダーファイル
#include<stdio.h>
#include <string.h>
#include <stdlib.h>

//プロトタイプ宣言
void nl();
void cr();
void add();
void new_item();
void ren(int,int,int);

//グローバル変数宣言
char gh[20];

//ここからメインプログラム
void main(void){
	
	int n;
	printf("\n====================================================\n");
	printf("	            注意\n");
	printf("  指定された値がある場合は文字を入れないでください\n");
	printf("====================================================\n");
	printf("\n制作済みのファイルに追記するなら     0を入力\n");
	printf("既存アイテムとのテクスチャ連携なら   1を入力\n");
	printf("新しいアイテムを作成するなら         2を入力\n");
	

	
	
	while(1){
		printf("\n");
		scanf("%d",&n);
		switch(n){
			
			case 0:
				cr();
				break;
				
			case 1:
				nl();
				break;
				
			case 2:
				new_item();
				break;
				
			default:
				printf("\n\n入力ミス\n");
				continue;
		}
	}
}

void nl(){
	
	char G[20]="generated";
	char H[20]="handheld_rod";
	char newtitle[20];
	
	int a;
	
	/*************************************************************************/
	/*持ち方の設定部分														 */
	/*持ち手の表示はghというグローバル変数に格納している。					 */
	/*************************************************************************/
	
	printf("\n持つ時の見た目は？\t\n\n");
	printf("普通の持ち方\t=1\n");
	printf("杖の持ち方\t=0\n\n");
		
	while(1){
		scanf("%d",&a);
		
		//判定部分
		switch(a){
			
			case 0:
				strcat(gh,H);
				add();
				break;
			
			case 1:
				strcat(gh,G);
				add();
				break;
			
			default:
				printf("\n\n入力ミス\n");
				continue;
		}
	}
}

//新しいアイテムの記述を行う
void new_item(){
	//変数宣言
	char old_name[50];
	char new_name[50];
	
	//マイクラアイテム入力
	printf("\n\nマイクラ公式のアイテム名を入力してください。\n\n");
	scanf("%s",old_name);
	
	//新規アイテム名入力
	printf("\n追加するアイテム名を入力してください。\n階層を深くしたい場合は\n  フォルダ名/アイテム名にしてください。\n\n");
	scanf("%s",new_name);
	
	//ファイル記述
	FILE *file;
    file=fopen("NEXT_ITEM.json","a+");
	fprintf(file,"{\n	\"parent\":\"item/%s\",\n	\"textures\":{\n		\"layer0\":\"item/%s\"\n	}\n}\n",old_name,new_name);
    fclose(file);
	
	exit(0);
}

//0を入力した時の処理つまり最初の部分書き込み
void add(){
	char name[50];
	
	//アイテム名追加
	printf("\nマイクラ公式のアイテム名を入力してください。\n\n");
	scanf("%s",name);
	
	
	//ファイル書き込み
	FILE *file;
    file=fopen("NODATA.json","a+");
	fprintf(file,"{\n	\"parent\":\"minecraft:item/%s\",\n	\"textures\":{\n	\"layer0\":\"minecraft:item/%s\"\n	},\n	\"overrides\":[\n",gh,name);
    fclose(file);
	
	//ファイルに追記するプログラムに引き継ぐ
	cr();
}

//ファイルに追記するプログラム上位4桁書き込み
void cr(){
	int a,b,c;
	int min,max;
	int sum;
	
	//ユーザーID
	printf("\nユーザーIDを入力\n10～99まで\n\n");
	while(1){
		scanf("%d",&a);
		
		//判定部分
		if(9<a && a<100){
			a=a*1000000;
			break;
		
		}
		else{
			printf("\n不正な値です。 %d\n\n",a);
		}
	}
	
	//ジャンル
	printf("\nジャンルを入力1～9まで\n");
	printf("1,2,3は\t自由空間\n");
	printf("4,5は\t工業系\n");
	printf("6,7は\t魔術系\n");
	printf("8,9は\t農業系\n\n");
	while(1){
    	scanf("%d",&b);
		
		//判定部分
		if(0 <= b && b<10 ){
			b=b*100000;
			break;
		}
		else{
			printf("\n不正な値です。 %d\n\n",b);
		}
	}
	
	//分類
	printf("\n分類を入力1～9まで\n");
	printf("1,2は\tツール\n");
	printf("3,4は\t武器\n");
	printf("5,6は\tエンティティ\n");
	printf("7,8,9は\tアイテム\n\n");
	
	while(1){
		scanf("%d",&c);
		
		//判定部分
		if(0<c && c<10){
			c=c*10000;
			break;
		}
		else{
			printf("\n不正な値です。 %d\n\n",c);
			
		}
	}
	
	//上の値を足す。
	sum=a+b+c;
	
	//繰り返し処理のための下準備
	//初期値
	printf("\n初期値を入力1～9999まで\n\n");
	while(1){
    	scanf("%d",&min);
		
		//判定部分
		if(0<min || c>10000){
			break;
		}
		else{
			printf("\n不正な値です。 %d\n\n",min);

		}
	}
	
	//上限値
	printf("\n上限値を入力%d～9999まで\n\n",min);
	while(1){
    	scanf("%d",&max);
		
		//判定部分
		if(min<max || max<10000){
			break;
		}
		else{
			printf("不正な値です。 %d\n\n",max);
		}
	}
	//連番処理へと引き渡す
	ren(min,max,sum);
}
void ren(int x,int y,int z){
	int i,id;
	
	id=z+x;
	for(i=x;i<=y;i++){
		
		//ファイル書き込み
		FILE *file;
    	file=fopen("NODATA.json","a+");
   		fprintf(file,"		{ \"predicate\": {\"custom_model_data\": %d}, \"model\": \"item/\"},\n",id);
    	fclose(file);
		
		//ここで連番を作成している
		id=id+1;
	}
	exit(1);
}
