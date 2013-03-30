void tempgScreen()//------------------------------------------------------------ tela =11
{
  int x, y, z, grafico;
  int16_t n;
  char buf[8];
  float temperatura;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // Soma dos valores de todos os elementos
  float media = 0.0f; // Média dos valores
  float linhaR;
  float linhaG;
  float linhaB;
  int f = 30;
 
  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[25])));
  printHeader(buffer); // tabela_textos[25] = "GRAFICO DE TEMPERATURA"

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

for(float i = 27.5; i > 22.0; i -= 0.5)
{
  myGLCD.printNumF(i, 1, 5, f);
  f += 15; 
}

f = 255;
for(int i = 22; i > 0; i -= 2)
{
  myGLCD.printNumI(i, f, 193);
  f -= 20;
}
  /* 
  myGLCD.print("22,5", 5, 180);
  myGLCD.print("23,0", 5, 165);
  myGLCD.print("23,5", 5, 150);
  myGLCD.print("24,0", 5, 135);
  myGLCD.print("24,5", 5, 120);
  myGLCD.print("25,0", 5, 105);
  myGLCD.print("25,5", 5, 90);
  myGLCD.print("26,0", 5, 75);
  myGLCD.print("26,5", 5, 60);
  myGLCD.print("27,0", 5, 45);
  myGLCD.print("27,5", 5, 30); 
 
  myGLCD.print("2", 60, 193);
  myGLCD.print("4", 80, 193);
  myGLCD.print("6", 100, 193);
  myGLCD.print("8", 120, 193);
  myGLCD.print("10", 135, 193);
  myGLCD.print("12", 155, 193);
  myGLCD.print("14", 175, 193);
  myGLCD.print("16", 195, 193);
  myGLCD.print("18", 215, 193);
  myGLCD.print("20", 235, 193);
  myGLCD.print("22", 255, 193);
  */
  myGLCD.print("0", 275, 193); 
   
  
  myGLCD.drawCircle(15, 21, 2);  
  myGLCD.print("C", 20, 18);
  myGLCD.print("H", 290, 193);

  myGLCD.drawLine(40, 30, 40, 190); // Eixo y
  myGLCD.drawLine(40, 190, 290, 190);  // Eixo x

  myGLCD.setColor(64, 64, 64);  // Malha

  //EIXO X
  for(int k=40; k<180; k+=15)
  {
    myGLCD.drawLine(40, k, 290, k);
  }

  //EIXO Y
  for(int l=60; l<300; l+=20)
  {
    myGLCD.drawLine(l, 30, l, 190);
  }

  linhaR =setTempC;   //  Linhas de comparação
  linhaG =(setTempC+offTempC);
  linhaB = (setTempC-offTempC);

  if ((linhaR>=22.5) && (linhaR<=27.5))
    x= (190-((linhaR-22.5)*30));

  else if (linhaR > 27.5)
    x=30;

  else if (linhaR < 22.5)
    x=190;

  if ((linhaG>=22.5) && (linhaG<=27.5))
    y= (190-((linhaG-22.5)*30));

  else if (linhaG > 27.5)
    y=30;

  else if (linhaG < 22.5)
    y=190;

  if ((linhaB>=22.5) && (linhaB<=27.5))
    z= (190-((linhaB-22.5)*30));

  else if (linhaB > 27.5)
    z=30;

  else if (linhaB < 22.5)
    z=190;

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(40, x, 290, x);// Temperatura desejada
  myGLCD.setColor(10, 10, 255);        // Variação permitida
  myGLCD.drawLine(40, y, 290, y); // Variação mais
  myGLCD.drawLine(40, z, 290, z); // Variação menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

  digitalWrite (4, LOW);
  file.open(&root, "LOGTDIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    temperatura = atof(buf);
    soma +=temperatura;

    if(strlen(buf)==5)
    {
      i++;
      k++;
    }

    if (temperatura <= 2 )
    {
      k -= 1;
    }

    if (i==6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) < 22.5)
      {
        grafico = 190;
      }
      else if ((media) > 27.5)
      {
        grafico = 30;
      }
      else if (22.5 <= media <= 27.5)
      {
        grafico = (190-((media-22.5)*30));
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);
      myGLCD.drawPixel((40+j),grafico);
    }
  }
  file.close();
  digitalWrite (4, HIGH);
}

void orpScreen()//------------------------------------------------------------tela =12
{
  int x, y, z;
  int orp = setORP;
  int orpmais = offORP;
  int orpmenos = offORP;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  int soma = 0; // soma dos valores de todos os elementos
  int media = 0; // média dos valores.
  int grafico;
  int16_t n;
  char buf[6];
  int redox;
  int f = 30;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[26])));
  printHeader(buffer); // tabela_textos[26] = "GRAFICO DE ORP"
  setFont(SMALL, 255, 255, 255, 0, 0, 0);
  
  for(int i = 480; i > 160; i -= 30)
{
  myGLCD.printNumI(i, 5, f);
  f += 15; 
}

f = 255;
for(int i = 22; i > 0; i -= 2)
{
  myGLCD.printNumI(i, f, 193);
  f -= 20;
}

/*
  myGLCD.print("180", 10, 180);
  myGLCD.print("210", 10, 165);
  myGLCD.print("240", 10, 150);
  myGLCD.print("270", 10, 135);
  myGLCD.print("300", 10, 120);
  myGLCD.print("330", 10, 105);
  myGLCD.print("360", 10, 90);
  myGLCD.print("390", 10, 75);
  myGLCD.print("420", 10, 60);
  myGLCD.print("450", 10, 45);
  myGLCD.print("480", 10, 30); 
  
  myGLCD.print("2", 55, 193);
  myGLCD.print("4", 75, 193);
  myGLCD.print("6", 95, 193);
  myGLCD.print("8", 115, 193);
  myGLCD.print("10", 135, 193);
  myGLCD.print("12", 155, 193);
  myGLCD.print("14", 175, 193);
  myGLCD.print("16", 195, 193);
  myGLCD.print("18", 215, 193);
  myGLCD.print("20", 235, 193);
  myGLCD.print("22", 255, 193);
  */
  
  myGLCD.print("0", 275, 193);    
  myGLCD.print("MV", 20, 18);
  myGLCD.print("H", 290, 193);
  myGLCD.drawLine(40, 190, 290, 190);  //eixo x
  myGLCD.drawLine(40, 30, 40, 190); //eixo y

  myGLCD.setColor(64, 64, 64);                    //malha

  //EIXO X
  for(int k=40; k<180; k+=15)
  {
    myGLCD.drawLine(40, k, 290, k);
  }

  //EIXOY
  for(int l = 60; l<300; l+=20)
  {
    myGLCD.drawLine(l, 30, l, 190);
  } 

  linhaR = orp;       //  Linhas de comparacao
  linhaG =(orp + orpmais);
  linhaB = (orp - orpmenos);

  if ((linhaR >= 180) && (linhaR <= 480))
    x = (190 - ((linhaR - 180) * 0.5));

  else if (linhaR > 480)
    x = 30;

  else if (linhaR < 180)
    x = 190;

  if ((linhaG > 180) && (linhaG <= 480))
    y = (190 - ((linhaG - 180) * 0.5));

  else if (linhaG > 480)
    y = 30;

  else if (linhaG < 180)
    y = 190;

  if ((linhaB > 180) && (linhaB <= 480))
    z = (190-((linhaB - 180) * 0.5));

  else if (linhaB > 480)
    z = 30;

  else if (linhaB < 180)
    z = 190;

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(40, x, 290, x);//Temperatura desejada
  myGLCD.setColor(10, 10, 255);        //Variacao permitida
  myGLCD.drawLine(40, y, 290, y); //variacao mais
  myGLCD.drawLine(40, z, 290, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3]); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3]);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3]);

  digitalWrite (4, LOW);
  file.open(&root, "LOGODIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    redox = atoi(buf);
    soma +=redox;


    if(strlen(buf)==3)
    {
      i++;
      k++;
    }

    if (redox <= 2 )
    {
      k -= 1;
    }

    if (i==6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) < 180)
      {
        grafico = 190;
      }
      else if ((media) > 480)
      {
        grafico = 30;
      }
      else if (180 <= media <= 480)
      {
        grafico = (190-((media - 180) * 0.5));
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);
      myGLCD.drawPixel((40+j),grafico);
    }
  }
  file.close();
  digitalWrite (4, HIGH);
}

void PHAScreen()//-------------------------------ph do aqua-----------------------------tela =13
{
  float x, y, z;
  float ph = setPHA;
  float phmais = offPHA;
  float phmenos = offPHA;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // soma dos valores de todos os elementos
  float media = 0.0f; // média dos valores.
  int grafico;
  int16_t n;
  char buf[7];
  float pht;
  int f = 30;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[27])));
  printHeader(buffer); //tabela_textos[27] = "GRAFICO DE PH DO AQUARIO"
  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  for(float i = 9; i > 6.9; i -= 0.2)
{
  myGLCD.printNumF(i, 1, 5, f);
  f += 15; 
}

f = 255;
for(int i = 22; i > 0; i -= 2)
{
  myGLCD.printNumI(i, f, 193);
  f -= 20;
}

/*
  myGLCD.print("7,0", 10, 180);
  myGLCD.print("7,2", 10, 165);
  myGLCD.print("7,4", 10, 150);
  myGLCD.print("7,6", 10, 135);
  myGLCD.print("7,8", 10, 120);
  myGLCD.print("8,0", 10, 105);
  myGLCD.print("8,2", 10, 90);
  myGLCD.print("8,4", 10, 75);
  myGLCD.print("8,6", 10, 60);
  myGLCD.print("8,8", 10, 45);
  myGLCD.print("9,0", 10, 30);  

  myGLCD.print("2", 55, 193);
  myGLCD.print("4", 75, 193);
  myGLCD.print("6", 95, 193);
  myGLCD.print("8", 115, 193);
  myGLCD.print("10", 135, 193);
  myGLCD.print("12", 155, 193);
  myGLCD.print("14", 175, 193);
  myGLCD.print("16", 195, 193);
  myGLCD.print("18", 215, 193);
  myGLCD.print("20", 235, 193);
  myGLCD.print("22", 255, 193);
  */
  myGLCD.print("0", 275, 193);   
  myGLCD.print("PH", 20, 18);
  myGLCD.print("H", 290, 193);

  myGLCD.drawLine(40, 30, 40, 190); //eixo y
  myGLCD.drawLine(40, 190, 290, 190);  //eixo x

  myGLCD.setColor(64, 64, 64);            //malha
  //EIXO X
  for(int k=40; k<180; k+=15)
  {
    myGLCD.drawLine(40, k, 290, k);
  }

  //EIXOY
  for(int l=60; l<300; l+=20)
  {
    myGLCD.drawLine(l, 30, l, 190);
  }

  linhaR =ph;  //  Linhas de comparacao
  linhaG =ph+phmais;
  linhaB =ph-phmenos;

  if ((linhaR>=7) && (linhaR<=9))
    x= 190-((linhaR-7)*75);

  else if (linhaR >9)
    x=30;

  else if (linhaR <7)
    x=190;

  if ((linhaG>=7) && (linhaG<=9))
    y= 190-((linhaG-7)*75);

  else if (linhaG >9)
    y=30;

  else if (linhaG <7)
    y=190;

  if ((linhaB>=7) && (linhaB<=9))
    z= 190-((linhaB-7)*75);

  else if (linhaB >9)
    z=30;

  else if (linhaB <7)
    z=190;

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(40, x, 290, x);//PH desejado
  myGLCD.setColor(10, 10, 255);  //Variacao permitida
  myGLCD.drawLine(40, y, 290, y); //variacao mais
  myGLCD.drawLine(40, z, 290, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3], false);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3],false);

  digitalWrite (4, LOW);
  file.open(&root, "LOGPDIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    pht = atof(buf);
    soma +=pht;

    if(strlen(buf)==4)
    {
      i++;
      k++;
    }

    if (pht <= 2 )
    {
      k -= 1;
    }

    if (i==6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) < 7)
      {
        grafico = 190;
      }
      else if ((media) > 9)
      {
        grafico = 30;
      }
      else if (7 <= media <= 9)
      {
        grafico = (190-((media-7)* 75));
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);
      myGLCD.drawPixel((40+j),grafico);
    }
  }
  file.close();
  digitalWrite (4, HIGH);
}

void PHRScreen()//----------------PH do reator --------------------------------------------tela =17
{
  float x, y, z;
  float ph = setPHR;
  float phmais = offPHR;
  float phmenos = offPHR;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  float soma = 0.0f; // soma dos valores de todos os elementos
  float media = 0.0f; // média dos valores.
  int grafico;
  int16_t n;
  char buf[7];
  float pht;
  int f = 30;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[28])));
  printHeader(buffer); //tabela_textos[28] = "GRAFICO DE PH DO REATOR DE CALCIO"

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  for(float i = 7.4; i > 5.3; i -= 0.2)
{
  myGLCD.printNumF(i, 1, 5, f);
  f += 15; 
}

f = 255;
for(int i = 22; i > 0; i -= 2)
{
  myGLCD.printNumI(i, f, 193);
  f -= 20;
}
/*
  myGLCD.print("5,4", 10, 180);
  myGLCD.print("5,6", 10, 165);
  myGLCD.print("5,8", 10, 150);
  myGLCD.print("6,0", 10, 135);
  myGLCD.print("6,2", 10, 120);
  myGLCD.print("6,4", 10, 105);
  myGLCD.print("6,6", 10, 90);
  myGLCD.print("6,8", 10, 75);
  myGLCD.print("7,0", 10, 60);
  myGLCD.print("7,2", 10, 45);
  myGLCD.print("7,4", 10, 30);  

  myGLCD.print("2", 55, 193);
  myGLCD.print("4", 75, 193);
  myGLCD.print("6", 95, 193);
  myGLCD.print("8", 115, 193);
  myGLCD.print("10", 135, 193);
  myGLCD.print("12", 155, 193);
  myGLCD.print("14", 175, 193);
  myGLCD.print("16", 195, 193);
  myGLCD.print("18", 215, 193);
  myGLCD.print("20", 235, 193);
  myGLCD.print("22", 255, 193);
*/
  myGLCD.print("0", 275, 193);   
  myGLCD.print("PH", 20, 18);
  myGLCD.print("H", 290, 193);

  myGLCD.drawLine(40, 30, 40, 190); //eixo y
  myGLCD.drawLine(40, 190, 290, 190);  //eixo x

  myGLCD.setColor(64, 64, 64);            //malha

  //EIXO X
  for(int k=40; k<180; k+=15)
  {
    myGLCD.drawLine(40, k, 290, k);
  }

  //EIXOY
  for(int l=60; l<300; l+=20)
  {
    myGLCD.drawLine(l, 30, l, 190);
  }

  linhaR =ph;  //  Linhas de comparacao
  linhaG =ph+phmais;
  linhaB =ph-phmenos;

  if ((linhaR>=5.4) && (linhaR<=7.4))
    x= 190-((linhaR-5.4)*75);

  else if (linhaR >7.4)
    x=30;

  else if (linhaR <5.4)
    x=190;

  if ((linhaG>=5.4) && (linhaG<=7.4))
    y= 190-((linhaG-5.4)*75);

  else if (linhaG >7.4)
    y=30;

  else if (linhaG <5.4)
    y=190;

  if ((linhaB>=5.4) && (linhaB<=7.4))
    z= 190-((linhaB-5.4)*75);

  else if (linhaB >7.4)
    z=30;

  else if (linhaB <5.4)
    z=190;

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(40, x, 290, x);//PH desejado
  myGLCD.setColor(10, 10, 255);  //Variacao permitida
  myGLCD.drawLine(40, y, 290, y); //variacao mais
  myGLCD.drawLine(40, z, 290, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3], false);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3],false);

  digitalWrite (4, LOW);
  file.open(&root, "LOGRDIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    pht = atof(buf);
    soma +=pht;

    if(strlen(buf)==4)
    {
      i++;
      k++;
    }
    if (pht <= 2 )
    {
      k -= 1;
    }
    if (i==6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) < 5.4)
      {
        grafico = 190;
      }
      else if ((media) > 7.4)
      {
        grafico = 30;
      }
      else if ( 5.4 <= media <= 7.4)
      {
        grafico = (190-((media-5.4)* 75));
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);
      myGLCD.drawPixel((40+j),grafico);
    }
  }
  file.close();
  digitalWrite (4, HIGH);
}

void densidadeScreen()//----------------grafico de densidade --------------------------------------------tela =19
{
  float x, y, z;
  float dens = setDEN;
  float densmais = offDEN;
  float densmenos = offDEN;
  float linhaR;
  float linhaG;
  float linhaB;
  int j = 0;
  int i = 0;
  int k = 0;
  int soma = 0; // soma dos valores de todos os elementos
  int media = 0; // média dos valores.
  int grafico;
  int16_t n;
  char buf[10];
  int densidade;
  int f = 30;

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[29])));
  printHeader(buffer); //tabela_textos[29] = "GRAFICO DE DENSIDADE"

  setFont(SMALL, 255, 255, 255, 0, 0, 0);

  for(int i = 1030; i > 1008; i -= 2)
{
  myGLCD.printNumI(i, 10, f);
  f += 15; 
}

f = 265;
for(int i = 22; i > 0; i -= 2)
{
  myGLCD.printNumI(i, f, 193);
  f -= 20;
}

/*
  myGLCD.print("1010", 10, 180);
  myGLCD.print("1012", 10, 165);
  myGLCD.print("1014", 10, 150);
  myGLCD.print("1016", 10, 135);
  myGLCD.print("1018", 10, 120);
  myGLCD.print("1020", 10, 105);
  myGLCD.print("1022", 10, 90);
  myGLCD.print("1024", 10, 75);
  myGLCD.print("1026", 10, 60);
  myGLCD.print("1028", 10, 45);
  myGLCD.print("1030", 10, 30);  

  myGLCD.print("2", 55, 193);
  myGLCD.print("4", 75, 193);
  myGLCD.print("6", 95, 193);
  myGLCD.print("8", 115, 193);
  myGLCD.print("10", 135, 193);
  myGLCD.print("12", 155, 193);
  myGLCD.print("14", 175, 193);
  myGLCD.print("16", 195, 193);
  myGLCD.print("18", 215, 193);
  myGLCD.print("20", 235, 193);
  myGLCD.print("22", 255, 193);
  */
  myGLCD.print("0", 285, 193);   
  myGLCD.print("DENS.", 10, 18);
  myGLCD.print("H", 300, 193);

  myGLCD.drawLine(50, 30, 50, 190); //eixo y
  myGLCD.drawLine(50, 190, 300, 190);  //eixo x
  //EIXO X
  myGLCD.setColor(64, 64, 64);            //malha

  //EIXO X
  for(int k=40; k<180; k+=15)
  {
    myGLCD.drawLine(50, k, 300, k);
  }

  //EIXOY
  for(int l=70; l < 300; l+=20)
  {
    myGLCD.drawLine(l, 30, l, 190);
  }


  linhaR =dens;  //  Linhas de comparacao
  linhaG =dens+densmais;
  linhaB =dens-densmenos;

  if ((linhaR>=1010) && (linhaR<=1030))
    x= 190-((linhaR-1010)*7.5);

  else if (linhaR >1030)
    x=30;

  else if (linhaR <1010)
    x=190;

  if ((linhaG>=1010) && (linhaG<=1030))
    y= 190-((linhaG-1010)*7.5);

  else if (linhaG >1030)
    y=30;

  else if (linhaG <1010)
    y=190;

  if ((linhaB>=1010) && (linhaB<=1030))
    z= 190-((linhaB-1010)*7.5);

  else if (linhaB >1030)
    z=30;

  else if (linhaB <1010)
    z=190;

  myGLCD.setColor(255, 0, 0);
  myGLCD.drawLine(50, x, 300, x);//PH desejado
  myGLCD.setColor(10, 10, 255);  //Variacao permitida
  myGLCD.drawLine(50, y, 300, y); //variacao mais
  myGLCD.drawLine(50, z, 300, z); //variacao menos

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[11])));
  printButton(buffer, iniC[0], iniC[1], iniC[2], iniC[3],false); 

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[1])));
  printButton(buffer, menU[0], menU[1], menU[2], menU[3], false);

  strcpy_P(buffer, (char*)pgm_read_word_near(&(tabela_textos[66])));
  printButton(buffer, volT[0], volT[1], volT[2], volT[3],false);

  digitalWrite (4, LOW);
  file.open(&root, "LOGDDIA.TXT", O_READ);
  while ((n = file.read(buf, sizeof(buf))) > 0)
  {
    densidade = atof(buf);
    soma +=densidade;

    if(strlen(buf)==4)
    {
      i++;
      k++;
    }
    if (densidade <= 2 )
    {
      k -= 1;
    }
    if (i==6)
    {
      media = soma / k;
      i = 0;
      j++;
      soma = 0;
      k = 0;

      if ((media) < 1010)
      {
        grafico = 190;
      }
      else if ((media) > 1030)
      {
        grafico = 30;
      }
      else if (1010 <= media <= 1030)
      {
        grafico = (190-((media-1010)*7.5));
      }
      setFont(SMALL, 255, 0, 255, 0, 0, 0);
      myGLCD.drawPixel((50+j),grafico);
    }
  }
  file.close();
  digitalWrite (4, HIGH);
}
