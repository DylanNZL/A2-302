#include <algorithm>
#include "fuzzylogic.h"

/////////////////////////////////////////////////////////////////

//Initialise Fuzzy Rules
void initFuzzyRules(fuzzy_system_rec *fl) {
  const int no_of_x_rules = 25, no_of_theta_rules = 25;
  int i;
  /*
  for (i = 0;i < no_of_theta_rules;i++) {
    fl->rules[i].inp_index[0] = in_theta;
    fl->rules[i].inp_index[1] = in_theta_dot;
    fl->rules[i + no_of_theta_rules].inp_index[0] = in_x;
   	fl->rules[i + no_of_theta_rules].inp_index[1] = in_x_dot;
    // NON DOT INPUTS
    int j = i / 5;
    switch (j) {
      case 0:
        fl->rules[i].inp_fuzzy_set[0] = in_nl;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[0] = in_nl;
        break;
      case 1:
        fl->rules[i].inp_fuzzy_set[0] = in_ns;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[0] = in_ns;
        break;
      case 2:
        fl->rules[i].inp_fuzzy_set[0] = in_ze;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[0] = in_ze;
        break;
      case 3:
        fl->rules[i].inp_fuzzy_set[0] = in_ps;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[0] = in_ps;
        break;
      case 4:
        fl->rules[i].inp_fuzzy_set[0] = in_pl;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[0] = in_pl;
        break;
    }
    // _DOT INPUTS
    j = i % 5;
    switch (j) {
      case 0:
        fl->rules[i].inp_fuzzy_set[1] = in_nl;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[1] = in_nl;
        break;
      case 1:
        fl->rules[i].inp_fuzzy_set[1] = in_ns;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[1] = in_ns;
        break;
      case 2:
        fl->rules[i].inp_fuzzy_set[1] = in_ze;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[1] = in_ze;
        break;
      case 3:
        fl->rules[i].inp_fuzzy_set[1] = in_ps;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[1] = in_ps;
        break;
      case 4:
        fl->rules[i].inp_fuzzy_set[1] = in_pl;
        fl->rules[i + no_of_theta_rules].inp_fuzzy_set[1] = in_pl;
        break;
      }
    }
  // THETA x THETA_DOT FAMM
  // THETA DOT = NL NS ZE PS PL (0 1 2 3 4)
  // Theta = NL
  fl->rules[ 0].out_fuzzy_set = out_nvl;
  fl->rules[ 1].out_fuzzy_set = out_nl;
  fl->rules[ 2].out_fuzzy_set = out_nm;
  fl->rules[ 3].out_fuzzy_set = out_ns;
  fl->rules[ 4].out_fuzzy_set = out_ze;
  // Theta = NS
  fl->rules[ 5].out_fuzzy_set = out_nl;
  fl->rules[ 6].out_fuzzy_set = out_nm;
  fl->rules[ 7].out_fuzzy_set = out_ns;
  fl->rules[ 8].out_fuzzy_set = out_ze;
  fl->rules[ 9].out_fuzzy_set = out_ps;
  // Theta = ZE
  fl->rules[10].out_fuzzy_set = out_nm;
  fl->rules[11].out_fuzzy_set = out_ns;
  fl->rules[12].out_fuzzy_set = out_ze;
  fl->rules[13].out_fuzzy_set = out_ps;
  fl->rules[14].out_fuzzy_set = out_pm;
  // Theta = PS
  fl->rules[15].out_fuzzy_set = out_ns;
  fl->rules[16].out_fuzzy_set = out_ze;
  fl->rules[17].out_fuzzy_set = out_ps;
  fl->rules[18].out_fuzzy_set = out_pm;
  fl->rules[19].out_fuzzy_set = out_pl;
  // Theta = PL
  fl->rules[20].out_fuzzy_set = out_ze;
  fl->rules[21].out_fuzzy_set = out_ps;
  fl->rules[22].out_fuzzy_set = out_pm;
  fl->rules[23].out_fuzzy_set = out_pl;
  fl->rules[24].out_fuzzy_set = out_pvl;
  // X x X_DOT FAMM
  // X DOT = NL NS ZE PS PL (1 2 3 4 5)
  // X = NL
  fl->rules[ 0 + no_of_theta_rules].out_fuzzy_set = out_pvl;
  fl->rules[ 1 + no_of_theta_rules].out_fuzzy_set = out_pl;
  fl->rules[ 2 + no_of_theta_rules].out_fuzzy_set = out_pm;
  fl->rules[ 3 + no_of_theta_rules].out_fuzzy_set = out_ps;
  fl->rules[ 4 + no_of_theta_rules].out_fuzzy_set = out_ze;
  // X = NS
  fl->rules[ 5 + no_of_theta_rules].out_fuzzy_set = out_pl;
  fl->rules[ 6 + no_of_theta_rules].out_fuzzy_set = out_pm;
  fl->rules[ 7 + no_of_theta_rules].out_fuzzy_set = out_ps;
  fl->rules[ 8 + no_of_theta_rules].out_fuzzy_set = out_ze;
  fl->rules[ 9 + no_of_theta_rules].out_fuzzy_set = out_ns;
  // X = ZE
  fl->rules[10 + no_of_theta_rules].out_fuzzy_set = out_pm;
  fl->rules[11 + no_of_theta_rules].out_fuzzy_set = out_ps;
  fl->rules[12 + no_of_theta_rules].out_fuzzy_set = out_ze;
  fl->rules[13 + no_of_theta_rules].out_fuzzy_set = out_ns;
  fl->rules[14 + no_of_theta_rules].out_fuzzy_set = out_nm;
  // X = PS
  fl->rules[15 + no_of_theta_rules].out_fuzzy_set = out_ps;
  fl->rules[16 + no_of_theta_rules].out_fuzzy_set = out_ze;
  fl->rules[17 + no_of_theta_rules].out_fuzzy_set = out_ns;
  fl->rules[18 + no_of_theta_rules].out_fuzzy_set = out_nm;
  fl->rules[19 + no_of_theta_rules].out_fuzzy_set = out_nl;
  // X = PL
  fl->rules[20 + no_of_theta_rules].out_fuzzy_set = out_ze;
  fl->rules[21 + no_of_theta_rules].out_fuzzy_set = out_ns;
  fl->rules[22 + no_of_theta_rules].out_fuzzy_set = out_nm;
  fl->rules[23 + no_of_theta_rules].out_fuzzy_set = out_nl;
  fl->rules[24 + no_of_theta_rules].out_fuzzy_set = out_nvl;
  */

  for (i = 0; i > 25; i++) {
    fl->rules[i].inp_index[0] = 0; // X
    fl->rules[i].inp_index[1] = 1; // Y
  }

  fl->rules[0].inp_fuzzy_set[0] = in_nl;
  fl->rules[1].inp_fuzzy_set[0] = in_ns;
  fl->rules[2].inp_fuzzy_set[0] = in_ze;
  fl->rules[3].inp_fuzzy_set[0] = in_ps;
  fl->rules[4].inp_fuzzy_set[0] = in_pl;
  fl->rules[5].inp_fuzzy_set[0] = in_nl;
  fl->rules[6].inp_fuzzy_set[0] = in_ns;
  fl->rules[7].inp_fuzzy_set[0] = in_ze;
  fl->rules[8].inp_fuzzy_set[0] = in_ps;
  fl->rules[9].inp_fuzzy_set[0] = in_pl;
  fl->rules[10].inp_fuzzy_set[0] = in_nl;
  fl->rules[11].inp_fuzzy_set[0] = in_ns;
  fl->rules[12].inp_fuzzy_set[0] = in_ze;
  fl->rules[13].inp_fuzzy_set[0] = in_ps;
  fl->rules[14].inp_fuzzy_set[0] = in_pl;
  fl->rules[15].inp_fuzzy_set[0] = in_nl;
  fl->rules[16].inp_fuzzy_set[0] = in_ns;
  fl->rules[17].inp_fuzzy_set[0] = in_ze;
  fl->rules[18].inp_fuzzy_set[0] = in_ps;
  fl->rules[19].inp_fuzzy_set[0] = in_pl;
  fl->rules[20].inp_fuzzy_set[0] = in_nl;
  fl->rules[21].inp_fuzzy_set[0] = in_ns;
  fl->rules[22].inp_fuzzy_set[0] = in_ze;
  fl->rules[23].inp_fuzzy_set[0] = in_ps;
  fl->rules[24].inp_fuzzy_set[0] = in_pl;

  fl->rules[0].inp_fuzzy_set[1] = in_nl;
  fl->rules[1].inp_fuzzy_set[1] = in_nl;
  fl->rules[2].inp_fuzzy_set[1] = in_nl;
  fl->rules[3].inp_fuzzy_set[1] = in_nl;
  fl->rules[4].inp_fuzzy_set[1] = in_nl;
  fl->rules[5].inp_fuzzy_set[1] = in_ns;
  fl->rules[6].inp_fuzzy_set[1] = in_ns;
  fl->rules[7].inp_fuzzy_set[1] = in_ns;
  fl->rules[8].inp_fuzzy_set[1] = in_ns;
  fl->rules[9].inp_fuzzy_set[1] = in_ns;
  fl->rules[10].inp_fuzzy_set[1] = in_ze;
  fl->rules[11].inp_fuzzy_set[1] = in_ze;
  fl->rules[12].inp_fuzzy_set[1] = in_ze;
  fl->rules[13].inp_fuzzy_set[1] = in_ze;
  fl->rules[14].inp_fuzzy_set[1] = in_ze;
  fl->rules[15].inp_fuzzy_set[1] = in_ps;
  fl->rules[16].inp_fuzzy_set[1] = in_ps;
  fl->rules[17].inp_fuzzy_set[1] = in_ps;
  fl->rules[18].inp_fuzzy_set[1] = in_ps;
  fl->rules[19].inp_fuzzy_set[1] = in_ps;
  fl->rules[20].inp_fuzzy_set[1] = in_pl;
  fl->rules[21].inp_fuzzy_set[1] = in_pl;
  fl->rules[22].inp_fuzzy_set[1] = in_pl;
  fl->rules[23].inp_fuzzy_set[1] = in_pl;
  fl->rules[24].inp_fuzzy_set[1] = in_pl;

  fl->rules[ 0].out_fuzzy_set = out_nvl;
  fl->rules[ 1].out_fuzzy_set = out_nl;
  fl->rules[ 2].out_fuzzy_set = out_nl;
  fl->rules[ 3].out_fuzzy_set = out_ns;
  fl->rules[ 4].out_fuzzy_set = out_ns;
  // Theta = NS
  fl->rules[ 5].out_fuzzy_set = out_nl;
  fl->rules[ 6].out_fuzzy_set = out_nm;
  fl->rules[ 7].out_fuzzy_set = out_ns;
  fl->rules[ 8].out_fuzzy_set = out_ns;
  fl->rules[ 9].out_fuzzy_set = out_nm;
  // Theta = ZE
  fl->rules[10].out_fuzzy_set = out_ns;
  fl->rules[11].out_fuzzy_set = out_ns;
  fl->rules[12].out_fuzzy_set = out_ze;
  fl->rules[13].out_fuzzy_set = out_ps;
  fl->rules[14].out_fuzzy_set = out_ps;
  // Theta = PS
  fl->rules[15].out_fuzzy_set = out_ps;
  fl->rules[16].out_fuzzy_set = out_ps;
  fl->rules[17].out_fuzzy_set = out_ps;
  fl->rules[18].out_fuzzy_set = out_pm;
  fl->rules[19].out_fuzzy_set = out_pl;
  // Theta = PL
  fl->rules[20].out_fuzzy_set = out_ps;
  fl->rules[21].out_fuzzy_set = out_ps;
  fl->rules[22].out_fuzzy_set = out_pl;
  fl->rules[23].out_fuzzy_set = out_pl;
  fl->rules[24].out_fuzzy_set = out_pvl;
  return;
}

void initMembershipFunctions(fuzzy_system_rec *fl) {
  /*
  // OUR TRAPz
  // The X membership functions
  // Between -2.4m & 2.4m
  fl->inp_mem_fns[in_x][in_nl] = init_trapz( 0,    0,   -3, -2.4,    left_trapezoid);    //
  fl->inp_mem_fns[in_x][in_ns] = init_trapz(-3, -2.4,   -2,   -1.5,  regular_trapezoid); //
  fl->inp_mem_fns[in_x][in_ze] = init_trapz(-2, -1.5,  1.5,  2,  regular_trapezoid); //
  fl->inp_mem_fns[in_x][in_ps] = init_trapz( 1.5,  2,    2.4,    3,  regular_trapezoid); //
  fl->inp_mem_fns[in_x][in_pl] = init_trapz( 2.4,    3,  0,    0,    right_trapezoid);   //
  // The X dot membership functions
  // Between -4.5m/s & 4.5m/s
  fl->inp_mem_fns[in_x_dot][in_nl] = init_trapz( 0,    0,   -5,   -4.5,   left_trapezoid);    //
  fl->inp_mem_fns[in_x_dot][in_ns] = init_trapz(-5,   -4.5, -2.5, -2, regular_trapezoid); //
  fl->inp_mem_fns[in_x_dot][in_ze] = init_trapz(-2.5, -2,    2,    2.5,   regular_trapezoid); //
  fl->inp_mem_fns[in_x_dot][in_ps] = init_trapz( 2,    2.5,  4.5,  5,  regular_trapezoid); //
  fl->inp_mem_fns[in_x_dot][in_pl] = init_trapz( 4.5,    2,  0,    0,   right_trapezoid);   //
  // The theta membership functions
  // Between -0.8 & 0.8 radians (-45 & 45 degrees)
  fl->inp_mem_fns[in_theta][in_nl] = init_trapz( 0,    0,   -0.6, -0.4,  left_trapezoid);    // -25 to -infinity
  fl->inp_mem_fns[in_theta][in_ns] = init_trapz(-0.7, -0.5, -0.1,  0, regular_trapezoid); // -25 to -5 degrees
  fl->inp_mem_fns[in_theta][in_ze] = init_trapz(-0.1, -0.03, 0.03, 0.1,  regular_trapezoid); // -5 to 5 degrees
  fl->inp_mem_fns[in_theta][in_ps] = init_trapz( 0, 0.1,  0.5,  0.7,  regular_trapezoid); //  5 to 25 degrees
  fl->inp_mem_fns[in_theta][in_pl] = init_trapz( 0.4,  0.6,  0,    0,    right_trapezoid);   // 25 to infinity
  // The theta dot membership functions
  // Between -0.4 & 0.4 Radians/Seconds (22 degrees)
  fl->inp_mem_fns[in_theta_dot][in_nl] = init_trapz( 0,     0,   -0.3, -0.25,  left_trapezoid);    //
  fl->inp_mem_fns[in_theta_dot][in_ns] = init_trapz(0,    -0.25, -0.1,  -0.03, regular_trapezoid); //
  fl->inp_mem_fns[in_theta_dot][in_ze] = init_trapz(-0.1, -0.03,  0.03,  0.1, regular_trapezoid); //
  fl->inp_mem_fns[in_theta_dot][in_ps] = init_trapz( 0,    0.1,   0.25,   0.3, regular_trapezoid); //
  fl->inp_mem_fns[in_theta_dot][in_pl] = init_trapz( 0.25, 0.3,   0,     0,    right_trapezoid);   //
  */

  // YAMAKAWA
  fl->inp_mem_fns[0][in_nl] = init_trapz( 0,     0,    -1.5,  -1.25,    left_trapezoid);    //
  fl->inp_mem_fns[0][in_ns] = init_trapz(-1.5,  -1,    -0.5,   0,  regular_trapezoid); //
  fl->inp_mem_fns[0][in_ze] = init_trapz(-0.5,  -0.25,  0.25,  0.5,   regular_trapezoid); //
  fl->inp_mem_fns[0][in_ps] = init_trapz( 0,  0.5,   1,     1.5,   regular_trapezoid); //
  fl->inp_mem_fns[0][in_pl] = init_trapz( 1.25,  1.5,   0,     0,     right_trapezoid);   //
  // The X dot membership functions
  // Between -4.5m/s & 4.5m/s
  fl->inp_mem_fns[1][in_nl] = init_trapz( 0,    0,     -0.3,  -0.25,  left_trapezoid);    // -25 to -infinity
  fl->inp_mem_fns[1][in_ns] = init_trapz(-0.3, -0.2,   -0.15,  0,    regular_trapezoid); // -25 to -5 degrees
  fl->inp_mem_fns[1][in_ze] = init_trapz(-0.1, -0.075,  0.075, 0.1,  regular_trapezoid); // -5 to 5 degrees
  fl->inp_mem_fns[1][in_ps] = init_trapz( 0,    0.15,   0.2,   0.3,  regular_trapezoid); //  5 to 25 degrees
  fl->inp_mem_fns[1][in_pl] = init_trapz( 0.25, 0.3,    0,     0,    right_trapezoid);   // 25 to infinity
  return;
}

void initFuzzySystem (fuzzy_system_rec *fl) {
  // NOTE: The settings of these parameters will depend upon your fuzzy system design
  fl->no_of_inputs = 2;  /* Inputs are handled 2 at a time only */
  fl->no_of_rules = 50;
  fl->no_of_inp_regions = 5;
  fl->no_of_outputs = 9;

  // NOTE: Fuzzy output terms
  // NOTE: enum {out_nvl, out_nl, out_nm, out_ns, out_ze, out_ps, out_pm, out_pl, out_pvl };
	fl->output_values[out_nvl] = -80.0;
	fl->output_values[out_nl]  = -40.0;
  fl->output_values[out_nm]  = -20.0;
	fl->output_values[out_ns]  = -10.0;
  fl->output_values[out_ze]  =  0.0;
	fl->output_values[out_ps]  =  10.0;
  fl->output_values[out_pm]  =  20.0;
	fl->output_values[out_pl]  =  40.0;
  fl->output_values[out_pvl] =  80.0;

  fl->rules = (rule *) malloc ((size_t)(fl->no_of_rules*sizeof(rule)));
  initFuzzyRules(fl);
  initMembershipFunctions(fl);

  // DEBUG: FOR CHECKING THE RULES INITIALISED CORRECTLY
  /*
  for (int i=0; i < 25; ++i) {
    cout << "RULE: " << i << endl;
    cout << "INPUT FUZZY SET 0: " << fl->rules[i].inp_fuzzy_set[0] << endl;
    cout << "INPUT FUZZY SET 1: " << fl->rules[i].inp_fuzzy_set[1] << endl;
    cout << "OUTPUT FUZZY SET: " << fl->rules[i].out_fuzzy_set << endl;
  }
  exit(123);*/
  return;
}

//////////////////////////////////////////////////////////////////////////////

trapezoid init_trapz (float x1,float x2,float x3,float x4, trapz_type typ) {
  trapezoid trz;
  trz.a = x1;
  trz.b = x2;
  trz.c = x3;
  trz.d = x4;
  trz.tp = typ;
  switch (trz.tp) {
    case regular_trapezoid:
      trz.l_slope = 1.0/(trz.b - trz.a);
      trz.r_slope = 1.0/(trz.c - trz.d);
      break;

    case left_trapezoid:
      trz.r_slope = 1.0/(trz.c - trz.d);
      trz.l_slope = 0.0;
      break;

    case right_trapezoid:
      trz.l_slope = 1.0/(trz.b - trz.a);
      trz.r_slope = 0.0;
      break;
  }  /* end switch  */
  return trz;
}  /* end function */

//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
float trapz (float x, trapezoid trz) {
  switch (trz.tp) {
    case left_trapezoid:
      if (x >= trz.d)
        return 0.0;
      if (x <= trz.c)
        return 1.0;
      /* a < x < b */
      return trz.r_slope * (x - trz.d);

    case right_trapezoid:
      if (x <= trz.a)
        return 0.0;
      if (x >= trz.b)
        return 1.0;
      /* a < x < b */
      return trz.l_slope * (x - trz.a);

    case regular_trapezoid:
      if ((x <= trz.a) || (x >= trz.d))
        return 0.0;
      if ((x >= trz.b) && (x <= trz.c))
         return 1.0;
      if ((x >= trz.a) && (x <= trz.b))
         return trz.l_slope * (x - trz.a);
      if ((x >= trz.c) && (x <= trz.d))
        return  trz.r_slope * (x - trz.d);
	 }  /* End switch  */
   return 0.0;  /* should not get to this point */
}  /* End function */

//////////////////////////////////////////////////////////////////////////////
float min_of(float values[],int no_of_inps) {
  int i;
  float val;
  val = values [0];
  for (i = 1;i < no_of_inps;i++) {
    if (values[i] < val) val = values [i];
  }
  return val;
}

//////////////////////////////////////////////////////////////////////////////
float fuzzy_system (float inputs[],fuzzy_system_rec fz) {
  int i,j;

  float x = (inputs[in_x] * 0.4) + (inputs[in_x_dot] * 0.6);
  float y = (inputs[in_theta] * 0.6) + (inputs[in_theta_dot] * 0.4);


  short variable_index,fuzzy_set_x, fuzzy_set_y;
  float sum1 = 0.0, sum2 = 0.0, weight;
  float m_values[MAX_NO_OF_INPUTS];
  //m_values[in_theta] = m_values[in_theta_dot] * 1.05;
  //m_values[in_theta_dot] = m_values[in_theta_dot] * 1.05;

  // DEBUG: INPUTS
  //cout << "THETA: " << inputs[in_theta] << endl;
  //cout << "THETA_DOT: " << inputs[in_theta_dot] << endl;
  //cout << "X: " << inputs[in_x] << endl;
  //cout << "X_DOT: " << inputs[in_x_dot] << endl;
  for (i = 0; i < 25; i++) {
    //cout << "i: " << i << endl;
    //cout << "X: " << x << endl;
    //cout << "Y: " << y << endl;
    fuzzy_set_x = fz.rules[i].inp_fuzzy_set[0];
    fuzzy_set_y = fz.rules[i].inp_fuzzy_set[1];

    //cout << "Fuzzy set x " << fuzzy_set_x << " Fuzzy set y " << fuzzy_set_y << endl;

    m_values[0] = trapz(x, fz.inp_mem_fns[0][fuzzy_set_x]);
    m_values[1] = trapz(y, fz.inp_mem_fns[1][fuzzy_set_y]);
    /*
    for (j = 0; j < 3; j++) {
	    variable_index = fz.rules[i].inp_index[j];
	    fuzzy_set = fz.rules[i].inp_fuzzy_set[j];
	    m_values[j] = trapz(inputs[variable_index], fz.inp_mem_fns[variable_index][fuzzy_set]);
	  } /* end j  */
    weight = min_of (m_values,fz.no_of_inputs);
    //if (i > 25) { weight = weight * 1.05; }
    sum1 += weight * fz.output_values[fz.rules[i].out_fuzzy_set];
    sum2 += weight;
  } /* end i  */

	if (fabs(sum2) < TOO_SMALL) {
    cout << "\r\nFLPRCS Error: Sum2 in fuzzy_system is 0.  Press key: " << endl;
    //~ getch();
    //~ exit(1);
    return 0.0;
  }
  // DEBUG: RESULTS
  //cout << "sum1 " << sum1 << " sum2 " << sum2 << " 1/2 " << sum1/sum2 << " Weight:" << weight << endl;
  //exit(123);
  return (sum1/sum2) * 2;
}  /* end fuzzy_system  */

//////////////////////////////////////////////////////////////////////////////
void free_fuzzy_rules (fuzzy_system_rec *fz) {
  if (fz->allocated){
	  free (fz->rules);
	}
  fz->allocated = false;
  return;
}

