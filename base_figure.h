using namespace std;

class BaseFigure{
protected:
    int type;
    int x_cell;
    int y_cell;
    //vector <int*> move_ability_cells;
    vector <int*> move_ability_cells;
public:
    BaseFigure(int type0, int x_cell0, int y_cell0);
    void move(int x_cell0, int  y_cell0);
    virtual void count_move_ability_cells(vector<BaseFigure*> figures){}
    virtual void change(){}
    virtual void draw(int x, int y, int r){}
    void update();

    int get_type();
    void set_type(int type0);
    int get_x_cell();
    void set_x_cell(int x_cell0);
    int get_y_cell();
    void set_y_cell(int y_cell0);
    vector <int*> get_move_ability_cells();
    void set_move_ability_cells(vector <int*> move_ability_cells0);
};

BaseFigure::BaseFigure(int type0, int x_cell0, int y_cell0): type(type0), x_cell(x_cell0), y_cell(y_cell0){}

void BaseFigure::move (int x_cell0, int y_cell0){
    x_cell = x_cell0;
    y_cell = y_cell0;
}

void BaseFigure::update(){
    //change();
    //draw();
}

int BaseFigure::get_type(){
    return type;
}

void BaseFigure::set_type(int type0){
    type = type0;
}


int BaseFigure::get_x_cell(){
    return x_cell;
}

void BaseFigure::set_x_cell(int x_cell0){
    x_cell = x_cell0;
}

int BaseFigure::get_y_cell(){
    return y_cell;
}

void BaseFigure::set_y_cell(int y_cell0){
    y_cell = y_cell0;
}

vector <int*> BaseFigure:: get_move_ability_cells(){
    return move_ability_cells;
}

void BaseFigure::set_move_ability_cells(vector <int*> move_ability_cells0){
    move_ability_cells = move_ability_cells0;
}
