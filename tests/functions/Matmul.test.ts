import { Matrix } from "../../dist/src/types/classes/Matrix";
import { Row } from "../../dist/src/types/classes/Row";
import { Col } from "../../dist/src/types/classes/Col";
import { Matmul } from "../../dist/src/types/functions/Matmul";
import { ObjEqualArray } from "../TestUtils";
import { getInstance } from "../../dist/src/types/Stream";

before("initialize", async function() {
  await getInstance();
});

describe("matmul", function() {
  it("int_int_mul_1", async function() {
    const matA: Matrix<number> = new Matrix<number>({ n_rows: 5, n_cols: 5 }, "int");
    await matA.init();

    const matB: Matrix<number> = new Matrix<number>({ n_rows: 5, n_cols: 2 }, "int");
    await matB.init();
    
    matA.fromArray([0, 2, 3, 4, 5,
                    5, 9, 1, 2, 3,
                    1, 2, 4, 1, 9,
                    3, 2, 1, 7, 9,
                    4, 5, 1, 7, 9]);
    
    matB.fromArray([0, 5,
                    2, 9,
                    3, 1,
                    4, 2,
                    5, 3,]);

    const ans: Array<number> = [54, 44,
                                44, 120,
                                65, 56,
                                80, 75,
                                86, 107];

    ObjEqualArray(await Matmul(matA, matB), ans);
  });

  it("int_int_mul_2", async function() {
    const matA: Matrix<number> = new Matrix<number>({ n_rows: 5, n_cols: 5 }, "int");
    await matA.init();

    const matB: Matrix<number> = new Col<number>({ n_rows: 5, n_cols: 1 }, "int");
    await matB.init();
    
    matA.fromArray([0, 2, 3, 4, 5,
                    5, 9, 1, 2, 3,
                    1, 2, 4, 1, 9,
                    3, 2, 1, 7, 9,
                    4, 5, 1, 7, 9]);
    
    matB.fromArray([0,
                    2,
                    3,
                    4,
                    5,]);

    const ans: Array<number> = [54,
                                44,
                                65,
                                80,
                                86];

    ObjEqualArray(await Matmul(matA, matB), ans);
  });

  it("int_int_mul_3", async function() {
    const matA: Matrix<number> = new Matrix<number>({ n_rows: 5, n_cols: 5 }, "int");
    await matA.init();

    const matB: Matrix<number> = new Row<number>({ n_rows: 1, n_cols: 5 }, "int");
    await matB.init();

    matA.fromArray([0, 2, 3, 4, 5,
                    5, 9, 1, 2, 3,
                    1, 2, 4, 1, 9,
                    3, 2, 1, 7, 9,
                    4, 5, 1, 7, 9]);

    matB.fromArray([0,
                    2,
                    3,
                    4,
                    5,]);

    const ans: Array<number> = [45,
                                57,
                                23,
                                70,
                                114];

    ObjEqualArray(await Matmul(matB, matA), ans);
  });

  it("float_int_1", async function() {
    const matA: Matrix<number> = new Matrix<number>({ n_rows: 5, n_cols: 5 }, "float");
    const matB: Matrix<number> = new Matrix<number>({ n_rows: 5, n_cols: 5 }, "int");

    await matA.init();
    await matB.init();

    matA.fromArray([0.12, 2.55, 3.21, 4.19, 5.23,
                    5.21, 9.67, 1.12, 2.33, 3.21,
                    1.21, 2.21, 4.43, 1.23, 9.35,
                    3.21, 2.67, 1.24, 7.24, 9.78,
                    4.15, 5.17, 1.85, 7.97, 9.62]);

    matB.fromArray([0, 2, 3, 4, 5,
                    5, 9, 1, 2, 3,
                    1, 2, 4, 1, 9,
                    3, 2, 1, 7, 9,
                    4, 5, 1, 7, 9]);

    const arr: Array<number> = [49.45, 64.14, 25.17, 74.73, 121.92,
                                69.3, 120.4, 35.32, 80.08, 115,
                                56.57, 80.38, 34.14, 87.75, 147.77,
                                75.43, 96.31, 34.28, 138.56, 188.4,
                                90.09, 122.57, 42.61, 151.92, 211.22];

    ObjEqualArray(await Matmul(matA, matB), arr, 1e-4);
  });

  it("float_float_1", async function() {
    const matA: Matrix<number> = new Matrix<number>({ n_rows: 5, n_cols: 5 }, "float");
    const matB: Matrix<number> = new Matrix<number>({ n_rows: 5, n_cols: 5 }, "float");

    await matA.init();
    await matB.init();

    matA.fromArray([0.12, 2.55, 3.21, 4.19, 5.23,
                    5.21, 9.67, 1.12, 2.33, 3.21,
                    1.21, 2.21, 4.43, 1.23, 9.35,
                    3.21, 2.67, 1.24, 7.24, 9.78,
                    4.15, 5.17, 1.85, 7.97, 9.62]);

    matB.fromArray([0.44, 2.45, 3.67, 4.19, 5.19,
                    5.33, 9.44, 1.12, 2.33, 3.72,
                    1.14, 2.11, 4.63, 1.23, 9.38,
                    3.23, 2.23, 1.98, 7.24, 9.23,
                    4.67, 5.12, 1.85, 7.66, 9.11]);

    const arr: Array<number> = [55.2615, 67.2604, 36.1304, 80.79, 126.5376,
                                77.6269, 128.0436, 45.6886, 87.1964, 124.2669,
                                64.9993, 83.7891, 47.1597, 96.1943, 152.5859,
                                86.1149, 101.9045, 52.9405, 148.5286, 194.1445,
                                102.1596, 129.9033, 63.164, 163.1021, 219.3252];

    ObjEqualArray(await Matmul(matA, matB), arr, 1e-4);
  });
});