class Checkme { // The following regular expression states the allowed order of method calls
// cm.create(), cm.init(), (cm.start(), cm.process()*, cm.finish())+, cm.reset()?

  void ok_minimal() {
    Botan2 p1 = new Botan2(1);
    p1.create();
    p1.init();
    p1.start();
    p1.process();
    p1.finish();
    p1.reset();
  }
  
  void nok2() {
    Botan2 p2 = new Botan2(1);
    Botan2 pX = p2;  // Alias before seed
    pX.init();       // NOK: create() missing
    pX.start();
    pX.process();
    pX.process();
    pX.process();
    pX.process();
    pX.finish();
  }

  void ok3() {
    Botan2 p3 = new Botan2(1);
    p3.create();
    p3.init();
    p3.start();
    p3.process();
    p3.finish();
  }

  void ok4() {
    Botan2 p4 = new Botan2(1);
    p4.create();
    p4.init();
    p4.start();
    p4.process();
    p4.finish();
    p4.start();
    p4.process();
    p4.finish();
  }

  void ok5() {
    Botan2 p4 = new Botan2(1);
    p4.create();
    p4.init();
    p4.start();
    if (someCondition) {
    	p4.process();
    } else {
    	p4.process();
    }
    p4.finish();
    p4 = blubb(p4);
    p4.process();
    p4.finish();
  }
  
  void nok1() {
    Botan2 p5 = new Botan2(1);
    p5.init();
    p5.start();
    p5.process();
    p5.finish();
  }
  
  void blubb(Botan2 myBotan) {
  	myBotan.start();
  	return myBotan;
  }

  void nok3() {
    Botan2 p6 = new Botan2(1);
    p6.create();
    p6.init();
    if (someCondition) {
      p6.start();
      p6.process();
      p6.finish();
    }
    p6.reset();
  }

  void nok4() {
      Botan2 p6 = new Botan2(1);
      while (true) {
        p6.create();
        p6.init();
        p6.start();
        p6.process();
        p6.finish();
      }
      p6.reset();
    }
}

class Botan2 {
  void create() {}

  void finish() {}

  void init() {}

  void process() {}

  void reset() {}

  void start() {}
}
