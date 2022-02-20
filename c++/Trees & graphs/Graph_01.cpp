#include<iostream>
#include<iterator>
#include <list>
#include<vector>
using namespace std;

class Edge
{
    public:
    int destinationvertex_id;
    int weighted;
    Edge(int dev,int wet)
    {
        destinationvertex_id=des;
        weighted=wet;
    }
    void set_Edge_value(int dec,int w)
    {
        destinationvertex_id=dec;
        weighted=w;
    }
    void setweight(int w)
    {
        weighted=w;
    }
    int getDestinationvertexid()
    {
        return destinationvertex_id;
    }
    int getweight()
        {
            return weighted;
        }

};


class vertex
{

    public:
    int id;
    string name;
    list<Edge> edgelist;
    vertex()
    {
        id=0;
        name="";
    }
    vertex(int id,string name)
    {
        id=id;
        name=name;
    }
    void setname(string name)
    {
        name=name;
    }
    void setid(int id)
    {
        id=id;
    }
    int getid()
    {
        return id;
    }
    
    list<Edge>getedgelist()
    {
        return edgelist;
    }

};



class Graph
{
    public:
    vector<vertex> vertices;
    
};





class Graph{
    private:
    int matrix[5][5];


};

int main()
{
    return 0;
}