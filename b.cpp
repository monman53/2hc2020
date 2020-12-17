#include <iostream>

#ifdef NDEBUG
#define DEBUG false
#else
#define DEBUG true
#endif

//================
// paramters
//================
constexpr int p_N_solution = 5;
// graph
constexpr int p_V = 225;
int p_E;
constexpr int _p_E_max = p_V * 2;
int p_u[_p_E_max], p_v[_p_E_max], p_d[_p_E_max];
// the weather pattern
enum DayType {
  sunny_without_downpour,
  sunny_with_downpour,
  rany_without_sudden_clear_sky,
  rany_with_sudden_clear_sky
};
DayType p_day_type;
// power predict
constexpr int p_N_div = 20;
constexpr int p_N_pattern = 3;
constexpr int p_variance_ele = 100;
double p_p_event;
constexpr int p_Delta_event = 1000;
int p_pw_predict[p_N_pattern][p_N_div];
// grid
constexpr int p_N_grid = 20;
constexpr int p_C_grid_init = 25000;
constexpr int p_C_grid_max = 50000;
constexpr int p_V_grid_max = 800;
int p_x[p_N_grid];
int p_pattern[p_N_grid];
// EV
constexpr int p_N_EV_min = 15;
constexpr int p_N_EV_max = 25;
int p_N_EV;
constexpr int p_C_EV_init = 12500;
constexpr int p_C_EV_max = 25000;
constexpr int p_V_EV_max = 400;
constexpr int p_N_trans_max = 4;
constexpr int p_Delta_EV_move = 50;
int p_pos[p_N_EV_max];
// transport
constexpr double p_p_const_trans = 0.7;
constexpr int p_T_last = 900;
// score
constexpr int p_P_trans = 3000;
constexpr double p_gamma = 2.0;
constexpr int p_S_ref_ele = -1'500'000;   // TODO: long?
constexpr int p_S_ref_trans = -1'500'000; // TODO: long?
constexpr int p_T_max = 1000;

// interactive inputs
int i_x[p_N_grid];
int i_y[p_N_grid];
int i_pw_actual[p_N_grid];
int i_pw_excess[p_N_grid];
int i_pw_buy[p_N_grid];
// carinfo
int i_charge[p_N_EV_max];
int i_u[p_N_EV_max], i_v[p_N_EV_max];
int i_dist_from_u[p_N_EV_max], i_dist_to_v[p_N_EV_max];
constexpr int _i_N_adj_max = 5;
int i_N_adj[p_N_EV_max], i_a[p_N_EV_max][_i_N_adj_max];
constexpr int _i_N_order_max = p_N_trans_max;
int i_N_order[p_N_EV_max], i_o[p_N_EV_max][_i_N_order_max];
// order rest
int i_N_order_rest;
constexpr int _i_N_order_rest_max = p_T_last;
int i_id[_i_N_order_max];
int i_w[_i_N_order_max];
int i_z[_i_N_order_max];
int i_state[_i_N_order_max];
int i_time[_i_N_order_max];

// score inputs
double s_S_trans, s_S_ele;

// variable for dummy inputs
int int_dummy;
double double_dummy;

void get_io_form_1() {
  std::cin >> int_dummy /* p_N_solution */;
  std::cin >> int_dummy /* p_V */ >> p_E;
  for (int i = 0; i < p_E; i++) {
    std::cin >> p_u[i] >> p_v[i] >> p_d[i];
  }
  int _p_day_type_int;
  std::cin >> _p_day_type_int;
  if (_p_day_type_int == 0)
    p_day_type = sunny_without_downpour;
  if (_p_day_type_int == 1)
    p_day_type = sunny_with_downpour;
  if (_p_day_type_int == 2)
    p_day_type = rany_without_sudden_clear_sky;
  if (_p_day_type_int == 3)
    p_day_type = rany_with_sudden_clear_sky;
  std::cin >> int_dummy /* p_N_div */ >> int_dummy /* p_N_pattern */ >>
      int_dummy /* p_variance_ele */ >> p_p_event >>
      int_dummy /* p_Delta_event */;
  for (int i = 0; i < p_N_pattern; i++) {
    for (int j = 0; j < p_N_div; j++) {
      std::cin >> p_pw_predict[i][j];
    }
  }
  std::cin >> int_dummy /* p_N_grid */ >> int_dummy /* p_C_grid_init */ >>
      int_dummy /* p_C_grid_max */ >> int_dummy /* p_V_grid_max */;
  for (int i = 0; i < p_N_grid; i++) {
    std::cin >> p_x[i] >> p_pattern[i];
  }
  std::cin >> p_N_EV >> int_dummy /* p_C_EV_init */ >>
      int_dummy /* p_C_EV_max */ >> int_dummy /* p_V_EV_max */ >>
      int_dummy /* p_N_trans_max */ >> int_dummy /* p_Delta_EV_move */;
  for (int i = 0; i < p_N_EV; i++) {
    std::cin >> p_pos[i];
  }
  std::cin >> double_dummy /* p_p_const_trans */ >> int_dummy /* p_T_last */;
  std::cin >> int_dummy /* p_P_trans */ >> double_dummy /* p_gamma */ >>
      int_dummy /* p_S_ref_ele */ >> int_dummy /* p_S_ref_trans */;
  std::cin >> int_dummy /* p_T_max */;

  if constexpr (DEBUG) {
    std::cerr << "get_io_form_1 done" << std::endl;
  }
}

void get_io_form_2(int solution_idx, int time) {
  for (int i = 0; i < p_N_grid; i++) {
    std::cin >> i_x[i] >> i_y[i] >> i_pw_actual[i] >> i_pw_excess[i] >>
        i_pw_buy[i];
  }
  for (int i = 0; i < p_N_EV; i++) {
    std::cin >> i_charge[i];
    std::cin >> i_u[i] >> i_v[i] >> i_dist_from_u[i] >> i_dist_to_v[i];
    std::cin >> i_N_adj[i];
    for (int j = 0; j < i_N_adj[i]; j++) {
      std::cin >> i_a[i][j];
    }
    std::cin >> i_N_order[i];
    for (int j = 0; j < i_N_order[i]; j++) {
      std::cin >> i_o[i][j];
    }
  }
  std::cin >> i_N_order_rest;
  for (int i = 0; i < i_N_order_rest; i++) {
    std::cin >> i_id[i] >> i_w[i] >> i_z[i] >> i_state[i] >> i_time[i];
  }

  if constexpr (DEBUG) {
    std::cerr << "get_io_form_2 done" << std::endl;
  }
}

void post_io_form_2(int solution_idx, int time) {
  for (int i = 0; i < p_N_EV; i++) {
    std::cout << "stay" << std::endl;
  }

  if constexpr (DEBUG) {
    std::cerr << "post_io_form_2 done" << std::endl;
  }
}

void get_io_form_3(int solution_idx) {
  std::cin >> s_S_trans >> s_S_ele;

  if constexpr (DEBUG) {
    std::cerr << "get_io_form_3 done" << std::endl;
  }
}

//================
// main
//================

int main() {
  get_io_form_1();
  for (int i = 0; i < p_N_solution; i++) {
    for (int j = 0; j < p_T_max; j++) {
      get_io_form_2(i, j);
      post_io_form_2(i, j);

      if constexpr (DEBUG) {
        std::cerr << "time " << j << " done" << std::endl;
      }
    }
    get_io_form_2(i, p_T_max);
    get_io_form_3(i);

    if constexpr (DEBUG) {
      std::cerr << "solution " << i << " done" << std::endl;
    }
  }
  return 0;
}
