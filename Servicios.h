#ifndef SERVICIOS_H
#define SERVICIOS_H

using namespace std;

class Content
{
  private:
  // atributos
  string title, age, rating, year, tomatoes;
  
  public:
  // constructor
  Content(string title = "", string age = "", string rating = "", string tomatoes = "", string year = "")
  {
    this -> title = title;
    this -> age = age;
    this -> rating = rating;
    this ->tomatoes = tomatoes;
    this ->year = year;
  }

  ~Content(){
    
  }

  // getters
  string getTitle()
  {
    return title;
  }

  string getAge()
  {
    return age;
  }
  
  string getRating()
  {
    return rating;
  }

  string getTomatoes()
  {
    return tomatoes;
  }

  string getYear()
  {
    return year;
  }

  virtual string getPlatform() = 0;

  // sobrecarga de operadores
  friend ostream& operator << (ostream& output, Content& content);
  
  protected: 
  
};

// sobrecarga de operadores
ostream& operator << (ostream& output, Content& content)
{
  output << "Título: " << content.getTitle() << ", Edad: " << content.getAge() << ", Rating: "<<content.getRating() <<", Rotten Tomatoes: "<<content.getTomatoes()<<", Year: "<<content.getYear() <<endl;
  
  return output;
}

// subclase de Content NETFLIX
class NetflixContent : public Content
{
  private:
  // atributos
  string platform;

  public:
  // constructor
  NetflixContent()
  {
    platform = "Netflix";
  }

  ~NetflixContent(){

  }

  NetflixContent(string title, string age, string rating, string tomatoes, string year): Content(title, age, rating, tomatoes, year)
  {
    this -> platform = "Netflix";
  }

  // getter
  string getPlatform()
  {
    return platform;
  }

  // sobrecarga de operadores
  friend ostream& operator << (ostream& output, NetflixContent& netflix);

  protected:

};

// sobrecarga de operadores
ostream& operator << (ostream& output,  NetflixContent& netflix)
{
  output << "Plataforma: " << netflix.getPlatform() << ", Título: " << netflix.getTitle() << ", Edad: " << netflix.getAge() << ", Rating: " << netflix.getRating() <<", Rotten Tomatoes: "<<netflix.getTomatoes()<<", Year: "<<netflix.getYear()<< endl;
  
  return output;
}

// subclase de Content PRIME
class PrimeContent : public Content
{
  private:
  // atributos
  string platform;

  public:
  // constructor
  PrimeContent()
  {
    platform = "Prime";
  }

  ~PrimeContent(){

  }

  PrimeContent(string title, string age, string rating, string tomatoes,string year): Content(title,age,rating,  tomatoes, year)
  {
    this -> platform = "Prime";
  }

  // getter
  string getPlatform()
  {
    return platform;
  }

  // sobrecarga de operadores
  friend ostream& operator << (ostream& output, PrimeContent& prime);

  protected:

};

// sobrecarga de operadores
ostream&  operator << (ostream& output, PrimeContent& prime)
{
  output << "Plataforma: " << prime.getPlatform() << ", Título: " << prime.getTitle() << ", Edad: " << prime.getAge() << ", Rating: " << prime.getRating() <<", Rotten Tomatoes: "<<prime.getTomatoes()<<", Year: "<<prime.getYear()<< endl;

  return output;
}

// subclase de Content DISNEY
class DisneyContent : public Content
{
  private:
  // atributos
  string platform;

  public:
  // constructor
  DisneyContent()
  {
    platform = "Disney";
  }

  ~DisneyContent(){

  }

  DisneyContent(string title, string age, string rating, string tomatoes,string year): Content(title, age, rating, tomatoes, year)
  {
    this -> platform = "Disney";
  }

  string getPlatform()
  {
    return platform;
  }

  // sobrecarga de operadores
  friend ostream& operator << (ostream& output,  DisneyContent& disney);

  protected:

};

// sobrecarga de operadores
ostream&  operator << (ostream& output,  DisneyContent& disney)
{
  output << "Plataforma: "<< disney.getPlatform() << ", Título: " << disney.getTitle() << ", Edad: " << disney.getAge() << ", Rating: " << disney.getRating() <<", Rotten Tomatoes: "<<disney.getTomatoes()<<", Year: "<<disney.getYear()<< endl;

  return output;
}


// clase de recomendador
class Recomendador
{
  private:
  // atributos
  vector <NetflixContent> netflix, salidaNetflix;
  vector <PrimeContent> prime, salidaPrime;
  vector <DisneyContent> disney, salidaDisney;
  void loadContent()
  {
    ifstream darchivo("disney.csv");
    string dline;
    getline(darchivo, dline);
    string dtitle, dyear, dage, dimdb, drotten_tomatoes;
    while(getline(darchivo, dline))
    {
      istringstream divdisney(dline);
      getline(divdisney, dtitle, ',');
      getline(divdisney, dyear, ',');
      getline(divdisney, dage, ',');
      getline(divdisney, dimdb, ',');
      getline(divdisney, drotten_tomatoes, ',');
      DisneyContent contd = DisneyContent(dtitle, dage, dimdb, drotten_tomatoes, dyear);
      disney.push_back(contd);
    }

    ifstream narchivo("netflix.csv");
    string nline;
    getline(narchivo, nline);
    string ntitle, nyear, nage, nimdb, nrotten_tomatoes;
    while(getline(narchivo, nline))
    {
      istringstream divnetflix(nline);
      getline(divnetflix, ntitle, ',');
      getline(divnetflix, nyear, ',');
      getline(divnetflix, nage, ',');
      getline(divnetflix, nimdb, ',');
      getline(divnetflix, nrotten_tomatoes, ',');
      NetflixContent cont = NetflixContent(ntitle, nage, nimdb, nrotten_tomatoes, nyear);
      netflix.push_back(cont);
    }

    ifstream parchivo("amazon.csv");
    string pline;
    getline(parchivo, pline);
    string ptitle, pyear, page, pimdb, protten_tomatoes;
    while(getline(parchivo, pline))
    {
      istringstream divprime(pline);
      getline(divprime, ptitle, ',');
      getline(divprime, pyear, ',');
      getline(divprime, page, ',');
      getline(divprime, pimdb, ',');
      getline(divprime, protten_tomatoes, ',');
      PrimeContent contp = PrimeContent(ptitle, page, pimdb, protten_tomatoes, pyear);
      prime.push_back(contp);
    }
  }

  public:
  // constructor
  Recomendador()
  {
    netflix = vector <NetflixContent>();
    prime = vector <PrimeContent>();
    disney = vector <DisneyContent>();
    loadContent();
  }
  ~Recomendador(){

  }
  int i = 0;
    void NconsultaPorTitulo(string consulta){
      vector<NetflixContent> salida = vector<NetflixContent>();
      for(int i = 0; i < netflix.size(); i++){
          if(netflix[i].getTitle().find(consulta) != string::npos ){
            salida.push_back(netflix[i]);
          }
      }
      i = 1;
      salidaNetflix = salida;
    }

    void NconsultaPorEdad(string consulta){
      vector<NetflixContent> salida = vector<NetflixContent>();
      for(int i = 0; i < netflix.size(); i++){
          if(netflix[i].getAge().find(consulta) != string::npos ){
            salida.push_back(netflix[i]);
          }
      }
      i = 1;
      salidaNetflix = salida;
    }

    void NconsultaPorRating(string consulta){
      vector<NetflixContent> salida = vector<NetflixContent>();
      for(int i = 0; i < netflix.size(); i++){
          if(netflix[i].getRating().find(consulta) != string::npos ){
            salida.push_back(netflix[i]);
          }
      }
      i = 1;
      salidaNetflix = salida;
    }

    void NconsultaPorTomatoes(string consulta){
      vector<NetflixContent> salida = vector<NetflixContent>();
      for(int i = 0; i < netflix.size(); i++){
          if(netflix[i].getTomatoes().find(consulta) != string::npos ){
            salida.push_back(netflix[i]);
          }
      }
      i = 1;
      salidaNetflix = salida;
    }

    void NconsultaPorYear(string consulta){
      vector<NetflixContent> salida = vector<NetflixContent>();
      for(int i = 0; i < netflix.size(); i++){
          if(netflix[i].getYear().find(consulta) != string::npos ){
            salida.push_back(netflix[i]);
          }
      }
      i = 1;
      salidaNetflix = salida;
    }

    void PconsultaPorTitulo(string consulta){
      vector<PrimeContent> salida = vector<PrimeContent>();
      for(int i = 0; i < prime.size(); i++){
          if(prime[i].getTitle().find(consulta) != string::npos ){
            salida.push_back(prime[i]);
          }
      }
      i = 2;
      salidaPrime = salida;
    }

    void PconsultaPorEdad(string consulta){
      vector<PrimeContent> salida = vector<PrimeContent>();
      for(int i = 0; i < prime.size(); i++){
          if(prime[i].getAge().find(consulta) != string::npos ){
            salida.push_back(prime[i]);
          }
      }
      i = 2;
      salidaPrime = salida;
    }

    void PconsultaPorRating(string consulta){
      vector<PrimeContent> salida = vector<PrimeContent>();
      for(int i = 0; i < prime.size(); i++){
          if(prime[i].getRating().find(consulta) != string::npos ){
            salida.push_back(prime[i]);
          }
      }
      i = 2;
      salidaPrime = salida;
    }

    void PconsultaPorTomatoes(string consulta){
      vector<PrimeContent> salida = vector<PrimeContent>();
      for(int i = 0; i < prime.size(); i++){
          if(prime[i].getTomatoes().find(consulta) != string::npos ){
            salida.push_back(prime[i]);
          }
      }
      i = 2;
      salidaPrime = salida;
    }

    void PconsultaPorYear(string consulta){
      vector<PrimeContent> salida = vector<PrimeContent>();
      for(int i = 0; i < prime.size(); i++){
          if(prime[i].getYear().find(consulta) != string::npos ){
            salida.push_back(prime[i]);
          }
      }
      i = 2;
      salidaPrime = salida;
    }

    void DconsultaPorTitulo(string consulta){
      vector<DisneyContent> salida = vector<DisneyContent>();
      for(int i = 0; i < disney.size(); i++){
          if(disney[i].getTitle().find(consulta) != string::npos ){
            salida.push_back(disney[i]);
          }
      }
      i = 3;

      salidaDisney = salida;
    }

    void DconsultaPorEdad(string consulta)
    {
      vector<DisneyContent> salida = vector<DisneyContent>();
      for(int i = 0; i < disney.size(); i++)
      {
          if(disney[i].getAge().find(consulta) != string::npos)
          {
            salida.push_back(disney[i]);
          }
      }

      i = 3;
      salidaDisney = salida;
    }

    void DconsultaPorRating(string consulta)
    {
      vector<DisneyContent> salida = vector<DisneyContent>();
      for(int i = 0; i < disney.size(); i++)
      {
        if(disney[i].getRating().find(consulta) != string::npos)
        {
          salida.push_back(disney[i]);
          }
      }  
      i = 3;
      salidaDisney = salida;
    }

    void DconsultaPorTomatoes(string consulta)
    {
      vector<DisneyContent> salida = vector<DisneyContent>();
      for(int i = 0; i < disney.size(); i++)
      {
        if(disney[i].getTomatoes().find(consulta) != string::npos)
        {
          salida.push_back(disney[i]);
          }
      }  
      i = 3;
      salidaDisney = salida;
    }

    void DconsultaPorYear(string consulta)
    {
      vector<DisneyContent> salida = vector<DisneyContent>();
      for(int i = 0; i < disney.size(); i++)
      {
        if(disney[i].getYear().find(consulta) != string::npos)
        {
          salida.push_back(disney[i]);
          }
      }  
      i = 3;
      salidaDisney = salida;
    }



    // sobrecarga de operadores
    friend ostream& operator<<(ostream & output, Recomendador & recomendador);

};

// sobrecarga de operadores
ostream& operator << (ostream& output, Recomendador& recomendador)
{
  if (recomendador.i == 1){
    if(recomendador.salidaNetflix.empty())
    {
        output << "Empty";
    }
    
    for(int i = 0; i < recomendador.salidaNetflix.size(); i++)
    {
        output << recomendador.salidaNetflix[i] << endl;
    }
    
    return output;
    }else if(recomendador.i == 2){
    if(recomendador.salidaPrime.empty())
    {
        output << "Empty";
    }
    
    for(int i = 0; i < recomendador.salidaPrime.size(); i++)
    {
        output << recomendador.salidaPrime[i] << endl;
    }
    
    return output;
    } else if(recomendador.i == 3){

    if(recomendador.salidaDisney.empty())
    {
        output << "Empty";
    }
    
    for(int i = 0; i < recomendador.salidaDisney.size(); i++)
    {
        output << recomendador.salidaDisney[i] << endl;
    }
    
    return output;
    }else{
      return output;
    }

}




#endif