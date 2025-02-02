/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */


// Description : Common matrix class


#ifndef CRYINCLUDE_CRYCOMMON_CRY_MATRIX34_H
#define CRYINCLUDE_CRYCOMMON_CRY_MATRIX34_H
#pragma once





///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// struct Matrix34_tpl
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
template <typename F>
struct Matrix34_tpl
{
    F m00, m01, m02, m03;
    F m10, m11, m12, m13;
    F m20, m21, m22, m23;

    //default constructor
#if defined(_DEBUG)
    ILINE Matrix34_tpl()
    {
        if constexpr (sizeof(F) == 4)
        {
            uint32* p = (uint32*)&m00;
            p[ 0] = F32NAN;
            p[ 1] = F32NAN;
            p[ 2] = F32NAN;
            p[ 3] = F32NAN;
            p[ 4] = F32NAN;
            p[ 5] = F32NAN;
            p[ 6] = F32NAN;
            p[ 7] = F32NAN;
            p[ 8] = F32NAN;
            p[ 9] = F32NAN;
            p[10] = F32NAN;
            p[11] = F32NAN;
        }
        if constexpr (sizeof(F) == 8)
        {
            uint64* p = (uint64*)&m00;
            p[ 0] = F64NAN;
            p[ 1] = F64NAN;
            p[ 2] = F64NAN;
            p[ 3] = F64NAN;
            p[ 4] = F64NAN;
            p[ 5] = F64NAN;
            p[ 6] = F64NAN;
            p[ 7] = F64NAN;
            p[ 8] = F64NAN;
            p[ 9] = F64NAN;
            p[10] = F64NAN;
            p[11] = F64NAN;
        }
    }
#else
    ILINE Matrix34_tpl(){};
#endif

    //set matrix to Identity
    ILINE Matrix34_tpl(type_identity)
    {
        m00 = 1;
        m01 = 0;
        m02 = 0;
        m03 = 0;
        m10 = 0;
        m11 = 1;
        m12 = 0;
        m13 = 0;
        m20 = 0;
        m21 = 0;
        m22 = 1;
        m23 = 0;
    }

    //set matrix to Zero
    ILINE Matrix34_tpl(type_zero)
    {
        m00 = 0;
        m01 = 0;
        m02 = 0;
        m03 = 0;
        m10 = 0;
        m11 = 0;
        m12 = 0;
        m13 = 0;
        m20 = 0;
        m21 = 0;
        m22 = 0;
        m23 = 0;
    }

    //ASSIGNMENT OPERATOR of identical Matrix33 types.
    //The assignment operator has precedence over assignment constructor
    //Matrix34 m; m=m34;
    ILINE Matrix34_tpl<F>& operator = (const Matrix34_tpl<F>& m)
    {
        assert(m.IsValid());
        m00 = m.m00;
        m01 = m.m01;
        m02 = m.m02;
        m03 = m.m03;
        m10 = m.m10;
        m11 = m.m11;
        m12 = m.m12;
        m13 = m.m13;
        m20 = m.m20;
        m21 = m.m21;
        m22 = m.m22;
        m23 = m.m23;
        return *this;
    }




    //--------------------------------------------------------------------
    //----   implementation of the constructors                        ---
    //--------------------------------------------------------------------


    //CONSTRUCTOR for identical float-types. It initialises a matrix34 with 12 floats.
    ILINE Matrix34_tpl<F>(F v00, F v01, F v02, F v03, F v10, F v11, F v12, F v13, F v20, F v21, F v22, F v23)
    {
        m00 = v00;
        m01 = v01;
        m02 = v02;
        m03 = v03;
        m10 = v10;
        m11 = v11;
        m12 = v12;
        m13 = v13;
        m20 = v20;
        m21 = v21;
        m22 = v22;
        m23 = v23;
    }
    //CONSTRUCTOR for different float-types. It initialises a matrix34 with 12 floats.
    template<class F1>
    ILINE Matrix34_tpl<F>(F1 v00, F1 v01, F1 v02, F1 v03, F1 v10, F1 v11, F1 v12, F1 v13, F1 v20, F1 v21, F1 v22, F1 v23)
    {
        m00 = F(v00);
        m01 = F(v01);
        m02 = F(v02);
        m03 = F(v03);
        m10 = F(v10);
        m11 = F(v11);
        m12 = F(v12);
        m13 = F(v13);
        m20 = F(v20);
        m21 = F(v21);
        m22 = F(v22);
        m23 = F(v23);
    }


    //CONSTRUCTOR for identical float-types. It converts a Matrix33 into a Matrix34.
    //Matrix34(m33);
    ILINE Matrix34_tpl<F>(const Matrix33_tpl<F>&m)
    {
        assert(m.IsValid());
        m00 = m.m00;
        m01 = m.m01;
        m02 = m.m02;
        m03 = 0;
        m10 = m.m10;
        m11 = m.m11;
        m12 = m.m12;
        m13 = 0;
        m20 = m.m20;
        m21 = m.m21;
        m22 = m.m22;
        m23 = 0;
    }
    //CONSTRUCTOR for different float-types. It converts a Matrix33 into a Matrix34 and also converts between double/float.
    //Matrix34(Matrix33);
    template<class F1>
    ILINE Matrix34_tpl<F>(const Matrix33_tpl<F1>&m)
    {
        assert(m.IsValid());
        m00 = F(m.m00);
        m01 = F(m.m01);
        m02 = F(m.m02);
        m03 = 0;
        m10 = F(m.m10);
        m11 = F(m.m11);
        m12 = F(m.m12);
        m13 = 0;
        m20 = F(m.m20);
        m21 = F(m.m21);
        m22 = F(m.m22);
        m23 = 0;
    }


    //CONSTRUCTOR for identical float-types. It converts a Matrix33 with a translation-vector into a Matrix34.
    //Matrix34(m33,Vec3(1,2,3));
    ILINE Matrix34_tpl<F>(const Matrix33_tpl<F>&m, const Vec3_tpl<F>&t)
    {
        assert(m.IsValid());
        assert(t.IsValid());
        m00 = m.m00;
        m01 = m.m01;
        m02 = m.m02;
        m03 = t.x;
        m10 = m.m10;
        m11 = m.m11;
        m12 = m.m12;
        m13 = t.y;
        m20 = m.m20;
        m21 = m.m21;
        m22 = m.m22;
        m23 = t.z;
    }
    //CONSTRUCTOR for different float-types. It converts a Matrix33 with a translation-vector into a Matrix34 and also converts between double/float.
    //Matrix34(Matrix33r,Vec3d(1,2,3));
    template<class F1>
    ILINE Matrix34_tpl<F>(const Matrix33_tpl<F1>&m, const Vec3_tpl<F1>&t)
    {
        assert(m.IsValid());
        assert(t.IsValid());
        m00 = F(m.m00);
        m01 = F(m.m01);
        m02 = F(m.m02);
        m03 = F(t.x);
        m10 = F(m.m10);
        m11 = F(m.m11);
        m12 = F(m.m12);
        m13 = F(t.y);
        m20 = F(m.m20);
        m21 = F(m.m21);
        m22 = F(m.m22);
        m23 = F(t.z);
    }



    //CONSTRUCTOR for identical float types
    //Matrix34 m=m34;
    ILINE Matrix34_tpl<F>(const Matrix34_tpl<F>&m)
    {
        assert(m.IsValid());
        m00 = m.m00;
        m01 = m.m01;
        m02 = m.m02;
        m03 = m.m03;
        m10 = m.m10;
        m11 = m.m11;
        m12 = m.m12;
        m13 = m.m13;
        m20 = m.m20;
        m21 = m.m21;
        m22 = m.m22;
        m23 = m.m23;
    }
    //CONSTRUCTOR for different float-types.
    //Matrix34 m=m34d;
    template<class F1>
    ILINE Matrix34_tpl<F>(const Matrix34_tpl<F1>&m)
    {
        assert(m.IsValid());
        m00 = F(m.m00);
        m01 = F(m.m01);
        m02 = F(m.m02);
        m03 = F(m.m03);
        m10 = F(m.m10);
        m11 = F(m.m11);
        m12 = F(m.m12);
        m13 = F(m.m13);
        m20 = F(m.m20);
        m21 = F(m.m21);
        m22 = F(m.m22);
        m23 = F(m.m23);
    }


    //CONSTRUCTOR for identical float-types. It converts a Matrix44 into a Matrix34.
    //Needs to be 'explicit' because we loose the translation vector in the conversion process
    //Matrix34(m44);
    ILINE explicit Matrix34_tpl<F>(const Matrix44_tpl<F>&m)
    {
        assert(m.IsValid());
        m00 = m.m00;
        m01 = m.m01;
        m02 = m.m02;
        m03 = m.m03;
        m10 = m.m10;
        m11 = m.m11;
        m12 = m.m12;
        m13 = m.m13;
        m20 = m.m20;
        m21 = m.m21;
        m22 = m.m22;
        m23 = m.m23;
    }
    //CONSTRUCTOR for different float types. It converts a Matrix44 into a Matrix34 and converts between double/float.
    //Needs to be 'explicit' because we loose the translation vector in the conversion process
    //Matrix34(m44r);
    template<class F1>
    ILINE explicit Matrix34_tpl<F>(const Matrix44_tpl<F1>&m)
    {
        assert(m.IsValid());
        m00 = F(m.m00);
        m01 = F(m.m01);
        m02 = F(m.m02);
        m03 = F(m.m03);
        m10 = F(m.m10);
        m11 = F(m.m11);
        m12 = F(m.m12);
        m13 = F(m.m13);
        m20 = F(m.m20);
        m21 = F(m.m21);
        m22 = F(m.m22);
        m23 = F(m.m23);
    }

    //CONSTRUCTOR for identical float-types. It converts a Quat into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    explicit ILINE Matrix34_tpl<F>(const Quat_tpl<F>&q)
    {
        *this = Matrix33_tpl<F>(q);
    }
    //CONSTRUCTOR for different float-types. It converts a Quat into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatTd);
    template<class F1>
    explicit ILINE Matrix34_tpl<F>(const Quat_tpl<F1>&q)
    {
        *this = Matrix33_tpl<F>(q);
    }



    //CONSTRUCTOR for identical float-types. It converts a QuatT into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    explicit ILINE Matrix34_tpl<F>(const QuatT_tpl<F> &q)
    {
        *this = Matrix34_tpl<F>(Matrix33_tpl<F>(q.q), q.t);
    }
    //CONSTRUCTOR for different float-types. It converts a QuatT into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    template<class F1>
    ILINE explicit Matrix34_tpl(const QuatT_tpl<F1> q)
    {
        *this = Matrix34_tpl<F>(Matrix33_tpl<F1>(q.q), q.t);
    }




    //CONSTRUCTOR for identical float-types. It converts a QuatTS into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    explicit ILINE Matrix34_tpl<F>(const QuatTS_tpl<F> &q)
    {
        assert(q.q.IsValid());
        Vec3_tpl<F> v2 = q.q.v + q.q.v;
        F xx = 1 - v2.x * q.q.v.x;
        F yy = v2.y * q.q.v.y;
        F xw = v2.x * q.q.w;
        F xy = v2.y * q.q.v.x;
        F yz = v2.z * q.q.v.y;
        F yw = v2.y * q.q.w;
        F xz = v2.z * q.q.v.x;
        F zz = v2.z * q.q.v.z;
        F zw = v2.z * q.q.w;
        m00 = (1 - yy - zz) * q.s;
        m01 = (xy - zw) * q.s;
        m02 = (xz + yw) * q.s;
        m03 = q.t.x;
        m10 = (xy + zw) * q.s;
        m11 = (xx - zz) * q.s;
        m12 = (yz - xw) * q.s;
        m13 = q.t.y;
        m20 = (xz - yw) * q.s;
        m21 = (yz + xw) * q.s;
        m22 = (xx - yy) * q.s;
        m23 = q.t.z;
    }
    //CONSTRUCTOR for different float-types. It converts a QuatTS into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    template<class F1>
    ILINE explicit Matrix34_tpl<F>(const QuatTS_tpl<F1> &q)
    {
        assert(q.q.IsValid());
        Vec3_tpl<F1> v2 = q.q.v + q.q.v;
        F1 xx = 1 - v2.x * q.q.v.x;
        F1 yy = v2.y * q.q.v.y;
        F1 xw = v2.x * q.q.w;
        F1 xy = v2.y * q.q.v.x;
        F1 yz = v2.z * q.q.v.y;
        F1 yw = v2.y * q.q.w;
        F1 xz = v2.z * q.q.v.x;
        F1 zz = v2.z * q.q.v.z;
        F1 zw = v2.z * q.q.w;
        m00 = F((1 - yy - zz) * q.s);
        m01 = F((xy - zw) * q.s);
        m02 = F((xz + yw) * q.s);
        m03 = F(q.t.x);
        m10 = F((xy + zw) * q.s);
        m11 = F((xx - zz) * q.s);
        m12 = F((yz - xw) * q.s);
        m13 = F(q.t.y);
        m20 = F((xz - yw) * q.s);
        m21 = F((yz + xw) * q.s);
        m22 = F((xx - yy) * q.s);
        m23 = F(q.t.z);
    }




    //CONSTRUCTOR for identical float-types. It converts a QuatTNS into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    explicit ILINE Matrix34_tpl<F>(const QuatTNS_tpl<F> &q)
    {
        assert(q.q.IsValid());
        Vec3_tpl<F> v2 = q.q.v + q.q.v;
        F xx = 1 - v2.x * q.q.v.x;
        F yy = v2.y * q.q.v.y;
        F xw = v2.x * q.q.w;
        F xy = v2.y * q.q.v.x;
        F yz = v2.z * q.q.v.y;
        F yw = v2.y * q.q.w;
        F xz = v2.z * q.q.v.x;
        F zz = v2.z * q.q.v.z;
        F zw = v2.z * q.q.w;
        m00 = (1 - yy - zz) * q.s.x;
        m01 = (xy - zw) * q.s.y;
        m02 = (xz + yw) * q.s.z;
        m03 = q.t.x;
        m10 = (xy + zw) * q.s.x;
        m11 = (xx - zz) * q.s.y;
        m12 = (yz - xw) * q.s.z;
        m13 = q.t.y;
        m20 = (xz - yw) * q.s.x;
        m21 = (yz + xw) * q.s.y;
        m22 = (xx - yy) * q.s.z;
        m23 = q.t.z;
    }
    //CONSTRUCTOR for different float-types. It converts a QuatTNS into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    template<class F1>
    ILINE explicit Matrix34_tpl<F>(const QuatTNS_tpl<F1> &q)
    {
        assert(q.q.IsValid());
        Vec3_tpl<F1> v2 = q.q.v + q.q.v;
        F1 xx = 1 - v2.x * q.q.v.x;
        F1 yy = v2.y * q.q.v.y;
        F1 xw = v2.x * q.q.w;
        F1 xy = v2.y * q.q.v.x;
        F1 yz = v2.z * q.q.v.y;
        F1 yw = v2.y * q.q.w;
        F1 xz = v2.z * q.q.v.x;
        F1 zz = v2.z * q.q.v.z;
        F1 zw = v2.z * q.q.w;
        m00 = F((1 - yy - zz) * q.s.x);
        m01 = F((xy - zw) * q.s.y);
        m02 = F((xz + yw) * q.s.z);
        m03 = F(q.t.x);
        m10 = F((xy + zw) * q.s.x);
        m11 = F((xx - zz) * q.s.y);
        m12 = F((yz - xw) * q.s.z);
        m13 = F(q.t.y);
        m20 = F((xz - yw) * q.s.x);
        m21 = F((yz + xw) * q.s.y);
        m22 = F((xx - yy) * q.s.z);
        m23 = F(q.t.z);
    }




    //CONSTRUCTOR for identical float-types. It converts a DualQuat into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    ILINE explicit Matrix34_tpl<F>(const DualQuat_tpl<F> &q)
    {
        assert((fabs_tpl(1 - (q.nq | q.nq))) < 0.01); //check if unit-quaternion
        Vec3_tpl<F>  t = (q.nq.w * q.dq.v - q.dq.w * q.nq.v + q.nq.v % q.dq.v); //perfect for HLSL
        Vec3_tpl<F> v2 = q.nq.v + q.nq.v;
        F xx = 1 - v2.x * q.nq.v.x;
        F yy = v2.y * q.nq.v.y;
        F xw = v2.x * q.nq.w;
        F xy = v2.y * q.nq.v.x;
        F yz = v2.z * q.nq.v.y;
        F yw = v2.y * q.nq.w;
        F xz = v2.z * q.nq.v.x;
        F zz = v2.z * q.nq.v.z;
        F zw = v2.z * q.nq.w;
        m00 = 1 - yy - zz;
        m01 = xy - zw;
        m02 = xz + yw;
        m03 = t.x + t.x;
        m10 = xy + zw;
        m11 = xx - zz;
        m12 = yz - xw;
        m13 = t.y + t.y;
        m20 = xz - yw;
        m21 = yz + xw;
        m22 = xx - yy;
        m23 = t.z + t.z;
    }
    //CONSTRUCTOR for different float-types. It converts a DualQuat into a Matrix34.
    //Needs to be 'explicit' because we loose float-precision in the conversion process
    //Matrix34(QuatT);
    template<class F1>
    ILINE explicit Matrix34_tpl<F>(const DualQuat_tpl<F1> &q)
    {
        assert((fabs_tpl(1 - (q.nq | q.nq))) < 0.01); //check if unit-quaternion
        Vec3_tpl<F1>  t = (q.nq.w * q.dq.v - q.dq.w * q.nq.v + q.nq.v % q.dq.v); //perfect for HLSL
        Vec3_tpl<F1> v2 = q.nq.v + q.nq.v;
        F1 xx = 1 - v2.x * q.nq.v.x;
        F1 yy = v2.y * q.nq.v.y;
        F1 xw = v2.x * q.nq.w;
        F1 xy = v2.y * q.nq.v.x;
        F1 yz = v2.z * q.nq.v.y;
        F1 yw = v2.y * q.nq.w;
        F1 xz = v2.z * q.nq.v.x;
        F1 zz = v2.z * q.nq.v.z;
        F1 zw = v2.z * q.nq.w;
        m00 = F(1 - yy - zz);
        m01 = F(xy - zw);
        m02 = F(xz + yw);
        m03 = F(t.x + t.x);
        m10 = F(xy + zw);
        m11 = F(xx - zz);
        m12 = F(yz - xw);
        m13 = F(t.y + t.y);
        m20 = F(xz - yw);
        m21 = F(yz + xw);
        m22 = F(xx - yy);
        m23 = F(t.z + t.z);
    }






    //apply scaling to the columns of the matrix.
    ILINE void ScaleColumn(const Vec3_tpl<F>& s)
    {
        m00 *= s.x;
        m01 *= s.y;
        m02 *= s.z;
        m10 *= s.x;
        m11 *= s.y;
        m12 *= s.z;
        m20 *= s.x;
        m21 *= s.y;
        m22 *= s.z;
    }

    /*!
    *
    *  Initializes the Matrix34 with the identity.
    *
    */
    void SetIdentity(void)
    {
        m00 = 1.0f;
        m01 = 0.0f;
        m02 = 0.0f;
        m03 = 0.0f;
        m10 = 0.0f;
        m11 = 1.0f;
        m12 = 0.0f;
        m13 = 0.0f;
        m20 = 0.0f;
        m21 = 0.0f;
        m22 = 1.0f;
        m23 = 0.0f;
    }

    ILINE static Matrix34_tpl<F> CreateIdentity(void)
    {
        Matrix34_tpl<F> m;
        m.SetIdentity();
        return m;
    }

    ILINE bool IsIdentity() const
    {
        return 0 == (fabs_tpl((F)1 - m00) + fabs_tpl(m01) + fabs_tpl(m02) + fabs_tpl(m03) + fabs_tpl(m10) + fabs_tpl((F)1 - m11) + fabs_tpl(m12) + fabs_tpl(m13) + fabs_tpl(m20) + fabs_tpl(m21) + fabs_tpl((F)1 - m22)) + fabs_tpl(m23);
    }

    ILINE int IsZero() const
    {
        return 0 == (fabs_tpl(m00) + fabs_tpl(m01) + fabs_tpl(m02) + fabs_tpl(m03) + fabs_tpl(m10) + fabs_tpl(m11) + fabs_tpl(m12) + fabs_tpl(m13) + fabs_tpl(m20) + fabs_tpl(m21) + fabs_tpl(m22)) + fabs_tpl(m23);
    }

    /*!
    *  Create a rotation matrix around an arbitrary axis (Eulers Theorem).
    *  The axis is specified as an normalized Vec3. The angle is assumed to be in radians.
    *  This function also assumes a translation-vector and stores it in the right column.
    *
    *  Example:
    *       Matrix34 m34;
    *       Vec3 axis=GetNormalized( Vec3(-1.0f,-0.3f,0.0f) );
    *       m34.SetRotationAA( 3.14314f, axis, Vec3(5,5,5) );
    */
    ILINE void SetRotationAA(const F rad, const Vec3_tpl<F>& axis, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        *this = Matrix33_tpl<F>::CreateRotationAA(rad, axis);
        this->SetTranslation(t);
    }
    ILINE static Matrix34_tpl<F> CreateRotationAA(const F rad, const Vec3_tpl<F>& axis, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Matrix34_tpl<F> m34;
        m34.SetRotationAA(rad, axis, t);
        return m34;
    }

    ILINE void SetRotationAA(const Vec3_tpl<F>& rot, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        *this = Matrix33_tpl<F>::CreateRotationAA(rot);
        this->SetTranslation(t);
    }
    ILINE static Matrix34_tpl<F> CreateRotationAA(const Vec3_tpl<F>& rot, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Matrix34_tpl<F> m34;
        m34.SetRotationAA(rot, t);
        return m34;
    }


    /*!
    * Create rotation-matrix about X axis using an angle.
    * The angle is assumed to be in radians.
    * The translation-vector is set to zero.
    *
    *  Example:
    *       Matrix34 m34;
    *       m34.SetRotationX(0.5f);
    */
    ILINE void SetRotationX(const f32 rad, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        *this = Matrix33_tpl<F>::CreateRotationX(rad);
        this->SetTranslation(t);
    }
    ILINE static Matrix34_tpl<F> CreateRotationX(const f32 rad, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Matrix34_tpl<F> m34;
        m34.SetRotationX(rad, t);
        return m34;
    }

    /*!
    * Create rotation-matrix about Y axis using an angle.
    * The angle is assumed to be in radians.
    * The translation-vector is set to zero.
    *
    *  Example:
    *       Matrix34 m34;
    *       m34.SetRotationY(0.5f);
    */
    ILINE void SetRotationY(const f32 rad, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        *this = Matrix33_tpl<F>::CreateRotationY(rad);
        this->SetTranslation(t);
    }
    ILINE static Matrix34_tpl<F> CreateRotationY(const f32 rad, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Matrix34_tpl<F> m34;
        m34.SetRotationY(rad, t);
        return m34;
    }

    /*!
    * Create rotation-matrix about Z axis using an angle.
    * The angle is assumed to be in radians.
    * The translation-vector is set to zero.
    *
    *  Example:
    *       Matrix34 m34;
    *       m34.SetRotationZ(0.5f);
    */
    ILINE void SetRotationZ(const f32 rad, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        *this = Matrix33_tpl<F>::CreateRotationZ(rad);
        this->SetTranslation(t);
    }
    ILINE static Matrix34_tpl<F> CreateRotationZ(const f32 rad, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Matrix34_tpl<F> m34;
        m34.SetRotationZ(rad, t);
        return m34;
    }


    /*!
    *
    * Convert three Euler angle to mat33 (rotation order:XYZ)
    * The Euler angles are assumed to be in radians.
    * The translation-vector is set to zero.
    *
    *  Example 1:
    *       Matrix34 m34;
    *       m34.SetRotationXYZ( Ang3(0.5f,0.2f,0.9f), translation );
    *
    *  Example 2:
    *       Matrix34 m34=Matrix34::CreateRotationXYZ( Ang3(0.5f,0.2f,0.9f), translation );
    */
    ILINE void SetRotationXYZ(const Ang3_tpl<F>& rad, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        assert(rad.IsValid());
        assert(t.IsValid());
        *this = Matrix33_tpl<F>::CreateRotationXYZ(rad);
        this->SetTranslation(t);
    }
    ILINE static Matrix34_tpl<F> CreateRotationXYZ(const Ang3_tpl<F>& rad, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        assert(rad.IsValid());
        assert(t.IsValid());
        Matrix34_tpl<F> m34;
        m34.SetRotationXYZ(rad, t);
        return m34;
    }


    ILINE void SetRotationAA(F c, F s, Vec3_tpl<F> axis, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        assert(axis.IsValid());
        assert(t.IsValid());
        *this = Matrix33_tpl<F>::CreateRotationAA(c, s, axis);
        m03 = t.x;
        m13 = t.y;
        m23 = t.z;
    }
    ILINE static Matrix34_tpl<F> CreateRotationAA(F c, F s, Vec3_tpl<F> axis, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Matrix34_tpl<F> m34;
        m34.SetRotationAA(c, s, axis, t);
        return m34;
    }

    ILINE void SetTranslationMat(const Vec3_tpl<F>& v)
    {
        m00 = 1.0f;
        m01 = 0.0f;
        m02 = 0.0f;
        m03 = v.x;
        m10 = 0.0f;
        m11 = 1.0f;
        m12 = 0.0f;
        m13 = v.y;
        m20 = 0.0f;
        m21 = 0.0f;
        m22 = 1.0f;
        m23 = v.z;
    }
    ILINE static Matrix34_tpl<F> CreateTranslationMat(const Vec3_tpl<F>& v)
    {
        Matrix34_tpl<F> m34;
        m34.SetTranslationMat(v);
        return m34;
    }


    //NOTE: all vectors are stored in columns
    ILINE void SetFromVectors(const Vec3& vx, const Vec3& vy, const Vec3& vz, const Vec3& pos)
    {
        m00 = vx.x;
        m01 = vy.x;
        m02 = vz.x;
        m03 = pos.x;
        m10 = vx.y;
        m11 = vy.y;
        m12 = vz.y;
        m13 = pos.y;
        m20 = vx.z;
        m21 = vy.z;
        m22 = vz.z;
        m23 = pos.z;
    }
    ILINE static Matrix34_tpl<F> CreateFromVectors(const Vec3_tpl<F>& vx, const Vec3_tpl<F>& vy, const Vec3_tpl<F>& vz, const Vec3_tpl<F>& pos)
    {
        Matrix34_tpl<F> m;
        m.SetFromVectors(vx, vy, vz, pos);
        return m;
    }

    void InvertFast()
    { // in-place transposition
        assert(IsOrthonormal());
        F t;
        Vec3 v(m03, m13, m23);
        t = m01;
        m01 = m10;
        m10 = t;
        m03 = -v.x * m00 - v.y * m01 - v.z * m20;
        t = m02;
        m02 = m20;
        m20 = t;
        m13 = -v.x * m10 - v.y * m11 - v.z * m21;
        t = m12;
        m12 = m21;
        m21 = t;
        m23 = -v.x * m20 - v.y * m21 - v.z * m22;
    }

    Matrix34_tpl<F> GetInvertedFast() const
    {
        assert(IsOrthonormal());
        Matrix34_tpl<F> dst;
        dst.m00 = m00;
        dst.m01 = m10;
        dst.m02 = m20;
        dst.m03 = -m03 * m00 - m13 * m10 - m23 * m20;
        dst.m10 = m01;
        dst.m11 = m11;
        dst.m12 = m21;
        dst.m13 = -m03 * m01 - m13 * m11 - m23 * m21;
        dst.m20 = m02;
        dst.m21 = m12;
        dst.m22 = m22;
        dst.m23 = -m03 * m02 - m13 * m12 - m23 * m22;
        return dst;
    }

    //! transforms a vector. the translation is not beeing considered
    ILINE Vec3_tpl<F> TransformVector(const Vec3_tpl<F>& v) const
    {
        assert(v.IsValid());
        return Vec3_tpl<F>(m00 * v.x + m01 * v.y + m02 * v.z, m10 * v.x + m11 * v.y + m12 * v.z, m20 * v.x + m21 * v.y + m22 * v.z);
    }
    //! transforms a point and add translation vector
    ILINE Vec3_tpl<F> TransformPoint(const Vec3_tpl<F>& p) const
    {
        assert(p.IsValid());
        return Vec3_tpl<F>(m00 * p.x + m01 * p.y + m02 * p.z + m03, m10 * p.x + m11 * p.y + m12 * p.z + m13, m20 * p.x + m21 * p.y + m22 * p.z + m23);
    }

    //! Remove scale from matrix.
    void OrthonormalizeFast()
    {
        Vec3_tpl<F> x(m00, m10, m20);
        Vec3_tpl<F> y(m01, m11, m21);
        Vec3_tpl<F> z;
        x = x.GetNormalized();
        z = (x % y).GetNormalized();
        y = (z % x).GetNormalized();
        m00 = x.x;
        m10 = x.y;
        m20 = x.z;
        m01 = y.x;
        m11 = y.y;
        m21 = y.z;
        m02 = z.x;
        m12 = z.y;
        m22 = z.z;
    }


    //determinant is ambiguous: only the upper-left-submatrix's determinant is calculated
    ILINE f32 Determinant() const
    {
        return (m00 * m11 * m22) + (m01 * m12 * m20) + (m02 * m10 * m21) - (m02 * m11 * m20) - (m00 * m12 * m21) - (m01 * m10 * m22);
    }


    //--------------------------------------------------------------------------------
    //----                  helper functions to access matrix-members     ------------
    //--------------------------------------------------------------------------------

    F* GetData() { return &m00; }
    const F* GetData() const { return &m00; }

    ILINE F operator () (uint32 i, uint32 j) const {    assert ((i < 3) && (j < 4));    F* p_data = (F*)(&m00);   return p_data[i * 4 + j];   }
    ILINE F& operator () (uint32 i, uint32 j)   {   assert ((i < 3) && (j < 4));    F* p_data = (F*)(&m00);       return p_data[i * 4 + j];   }

    ILINE void SetRow(int i, const Vec3_tpl<F>& v)  {   assert(i < 3);    F* p = (F*)(&m00);    p[0 + 4 * i] = v.x;   p[1 + 4 * i] = v.y;   p[2 + 4 * i] = v.z;       }

    ILINE const Vec3_tpl<F>& GetRow(int i) const    {   assert(i < 3); return *(const Vec3_tpl<F>*)(&m00 + 4 * i);  }
    ILINE const Vec4_tpl<F>& GetRow4(int i) const   {   assert(i < 3); return *(const Vec4_tpl<F>*)(&m00 + 4 * i);  }

    ILINE void SetColumn(int i, const Vec3_tpl<F>& v)   {   assert(i < 4);    F* p = (F*)(&m00);    p[i + 4 * 0] = v.x;   p[i + 4 * 1] = v.y;   p[i + 4 * 2] = v.z;       }
    ILINE Vec3_tpl<F> GetColumn(int i) const    {   assert(i < 4);    F* p = (F*)(&m00);    return Vec3(p[i + 4 * 0], p[i + 4 * 1], p[i + 4 * 2]);    }
    ILINE Vec3_tpl<F> GetColumn0() const    { return Vec3_tpl<F>(m00, m10, m20);  }
    ILINE Vec3_tpl<F> GetColumn1() const    { return Vec3_tpl<F>(m01, m11, m21);  }
    ILINE Vec3_tpl<F> GetColumn2() const    { return Vec3_tpl<F>(m02, m12, m22);  }
    ILINE Vec3_tpl<F> GetColumn3() const    { return Vec3_tpl<F>(m03, m13, m23);  }


    ILINE void SetTranslation(const Vec3_tpl<F>& t) { m03 = t.x;    m13 = t.y; m23 = t.z;   }
    ILINE Vec3_tpl<F> GetTranslation() const { return Vec3_tpl<F>(m03, m13, m23); }
    ILINE void ScaleTranslation (F s)                       {   m03 *= s;     m13 *= s;     m23 *= s;     }
    ILINE Matrix34_tpl<F> AddTranslation(const Vec3_tpl<F>& t)    {   m03 += t.x;   m13 += t.y;   m23 += t.z;   return *this; }

    ILINE void SetRotation33(const Matrix33_tpl<F>& m33)
    {
        m00 = m33.m00;
        m01 = m33.m01;
        m02 = m33.m02;
        m10 = m33.m10;
        m11 = m33.m11;
        m12 = m33.m12;
        m20 = m33.m20;
        m21 = m33.m21;
        m22 = m33.m22;
    }

    ILINE void GetRotation33(Matrix33_tpl<F>& m33) const
    {
        m33.m00 = m00;
        m33.m01 = m01;
        m33.m02 = m02;
        m33.m10 = m10;
        m33.m11 = m11;
        m33.m12 = m12;
        m33.m20 = m20;
        m33.m21 = m21;
        m33.m22 = m22;
    }

    //check if we have an orthonormal-base (general case, works even with reflection matrices)
    int IsOrthonormal(F threshold = 0.001) const
    {
        f32 d0 = fabs_tpl(GetColumn0() | GetColumn1());
        if  (d0 > threshold)
        {
            return 0;
        }
        f32 d1 = fabs_tpl(GetColumn0() | GetColumn2());
        if  (d1 > threshold)
        {
            return 0;
        }
        f32 d2 = fabs_tpl(GetColumn1() | GetColumn2());
        if  (d2 > threshold)
        {
            return 0;
        }
        int a = (fabs_tpl(1 - (GetColumn0() | GetColumn0()))) < threshold;
        int b = (fabs_tpl(1 - (GetColumn1() | GetColumn1()))) < threshold;
        int c = (fabs_tpl(1 - (GetColumn2() | GetColumn2()))) < threshold;
        return a & b & c;
    }

    //check if we have an orthonormal-base (assuming we are using a right-handed coordinate system)
    int IsOrthonormalRH(F threshold = 0.001) const
    {
        int a = Vec3_tpl<F>::IsEquivalent(GetColumn0(), GetColumn1() % GetColumn2(), threshold);
        int b = Vec3_tpl<F>::IsEquivalent(GetColumn1(), GetColumn2() % GetColumn0(), threshold);
        int c = Vec3_tpl<F>::IsEquivalent(GetColumn2(), GetColumn0() % GetColumn1(), threshold);
        return a & b & c;
    }
    bool static IsEquivalent(const Matrix34_tpl<F>& m0, const Matrix34_tpl<F>& m1, F e = VEC_EPSILON)
    {
        return  (
            (fabs_tpl(m0.m00 - m1.m00) <= e) && (fabs_tpl(m0.m01 - m1.m01) <= e) && (fabs_tpl(m0.m02 - m1.m02) <= e) && (fabs_tpl(m0.m03 - m1.m03) <= e) &&
            (fabs_tpl(m0.m10 - m1.m10) <= e) && (fabs_tpl(m0.m11 - m1.m11) <= e) && (fabs_tpl(m0.m12 - m1.m12) <= e) && (fabs_tpl(m0.m13 - m1.m13) <= e) &&
            (fabs_tpl(m0.m20 - m1.m20) <= e) && (fabs_tpl(m0.m21 - m1.m21) <= e) && (fabs_tpl(m0.m22 - m1.m22) <= e) && (fabs_tpl(m0.m23 - m1.m23) <= e)
            );
    }

    bool IsValid() const
    {
        if (!NumberValid(m00))
        {
            return false;
        }
        if (!NumberValid(m01))
        {
            return false;
        }
        if (!NumberValid(m02))
        {
            return false;
        }
        if (!NumberValid(m03))
        {
            return false;
        }
        if (!NumberValid(m10))
        {
            return false;
        }
        if (!NumberValid(m11))
        {
            return false;
        }
        if (!NumberValid(m12))
        {
            return false;
        }
        if (!NumberValid(m13))
        {
            return false;
        }
        if (!NumberValid(m20))
        {
            return false;
        }
        if (!NumberValid(m21))
        {
            return false;
        }
        if (!NumberValid(m22))
        {
            return false;
        }
        if (!NumberValid(m23))
        {
            return false;
        }
        return true;
    }


    bool IsDegenerate(float epsilon = FLT_EPSILON) const
    {
        //check the basis vectors for 0 vector
        return GetColumn0().len2() < epsilon
               || GetColumn1().len2() < epsilon
               || GetColumn2().len2() < epsilon;
    }

    /*!
    * Create a matrix with SCALING, ROTATION and TRANSLATION (in this order).
    *
    *  Example 1:
    *       Matrix m34;
    *       m34.SetMatrix( Vec3(1,2,3), quat, Vec3(11,22,33)  );
    */
    ILINE void Set(const Vec3_tpl<F>& s, const Quat_tpl<F>& q, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        assert(s.IsValid());
        assert(q.IsUnit(0.1f));
        assert(t.IsValid());
        F vxvx = q.v.x * q.v.x;
        F vzvz = q.v.z * q.v.z;
        F vyvy = q.v.y * q.v.y;
        F vxvy = q.v.x * q.v.y;
        F vxvz = q.v.x * q.v.z;
        F vyvz = q.v.y * q.v.z;
        F svx = q.w * q.v.x;
        F svy = q.w * q.v.y;
        F svz = q.w * q.v.z;
        m00 = (1 - (vyvy + vzvz) * 2) * s.x;
        m01 = (vxvy - svz) * 2 * s.y;
        m02 = (vxvz + svy) * 2 * s.z;
        m03 = t.x;
        m10 = (vxvy + svz) * 2 * s.x;
        m11 = (1 - (vxvx + vzvz) * 2) * s.y;
        m12 = (vyvz - svx) * 2 * s.z;
        m13 = t.y;
        m20 = (vxvz - svy) * 2 * s.x;
        m21 = (vyvz + svx) * 2 * s.y;
        m22 = (1 - (vxvx + vyvy) * 2) * s.z;
        m23 = t.z;
    }
    ILINE static Matrix34_tpl<F> Create(const Vec3_tpl<F>& s, const Quat_tpl<F>& q, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Matrix34_tpl<F> m34;
        m34.Set(s, q, t);
        return m34;
    }
    Matrix34_tpl(const Vec3_tpl<F>& s, const Quat_tpl<F>& q, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Set(s, q, t);
    }


    /*!
    * Create scaling-matrix.
    * The translation-vector is set to zero.
    *
    *  Example 1:
    *       Matrix m34;
    *       m34.SetScale( Vec3(0.5f, 1.0f, 2.0f) );
    *  Example 2:
    *       Matrix34 m34 = Matrix34::CreateScale( Vec3(0.5f, 1.0f, 2.0f) );
    */
    ILINE void SetScale(const Vec3_tpl<F>& s, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        *this = Matrix33::CreateScale(s);
        this->SetTranslation(t);
    }
    ILINE static Matrix34_tpl<F> CreateScale(const Vec3_tpl<F>& s, const Vec3_tpl<F>& t = Vec3(ZERO))
    {
        Matrix34_tpl<F> m34;
        m34.SetScale(s, t);
        return m34;
    }


    ILINE Matrix44_tpl<F> GetTransposed() const
    {
        Matrix44_tpl<F> tmp;
        tmp.m00 = m00;
        tmp.m01 = m10;
        tmp.m02 = m20;
        tmp.m03 = 0;
        tmp.m10 = m01;
        tmp.m11 = m11;
        tmp.m12 = m21;
        tmp.m13 = 0;
        tmp.m20 = m02;
        tmp.m21 = m12;
        tmp.m22 = m22;
        tmp.m23 = 0;
        tmp.m30 = m03;
        tmp.m31 = m13;
        tmp.m32 = m23;
        tmp.m33 = 1;
        return tmp;
    }

    /*!
    * calculate a real inversion of a Matrix34
    * an inverse-matrix is an UnDo-matrix for all kind of transformations
    *
    *  Example 1:
    *       Matrix34 im34; im34.Invert();
    *
    *  Example 2:
    *   Matrix34 im34 = m34.GetInverted();
    */
    void Invert(void)
    {
        //rescue members
        Matrix34_tpl<F> m = *this;
        // calculate 12 cofactors
        m00 = m.m22 * m.m11 - m.m12 * m.m21;
        m10 = m.m12 * m.m20 - m.m22 * m.m10;
        m20 = m.m10 * m.m21 - m.m20 * m.m11;
        m01 = m.m02 * m.m21 - m.m22 * m.m01;
        m11 = m.m22 * m.m00 - m.m02 * m.m20;
        m21 = m.m20 * m.m01 - m.m00 * m.m21;
        m02 = m.m12 * m.m01 - m.m02 * m.m11;
        m12 = m.m02 * m.m10 - m.m12 * m.m00;
        m22 = m.m00 * m.m11 - m.m10 * m.m01;
        m03 = (m.m22 * m.m13 * m.m01 + m.m02 * m.m23 * m.m11 + m.m12 * m.m03 * m.m21) - (m.m12 * m.m23 * m.m01 + m.m22 * m.m03 * m.m11 + m.m02 * m.m13 * m.m21);
        m13 = (m.m12 * m.m23 * m.m00 + m.m22 * m.m03 * m.m10 + m.m02 * m.m13 * m.m20) - (m.m22 * m.m13 * m.m00 + m.m02 * m.m23 * m.m10 + m.m12 * m.m03 * m.m20);
        m23 = (m.m20 * m.m11 * m.m03 + m.m00 * m.m21 * m.m13 + m.m10 * m.m01 * m.m23) - (m.m10 * m.m21 * m.m03 + m.m20 * m.m01 * m.m13 + m.m00 * m.m11 * m.m23);
        // calculate determinant
        F det = m.m00 * m00 + m.m10 * m01 + m.m20 * m02;
        assert(fabs_tpl(det) > (F)0.00000001);
        F rcpDet = 1.0f / det;
        // calculate matrix inverse/
        m00 *= rcpDet;
        m01 *= rcpDet;
        m02 *= rcpDet;
        m03 *= rcpDet;
        m10 *= rcpDet;
        m11 *= rcpDet;
        m12 *= rcpDet;
        m13 *= rcpDet;
        m20 *= rcpDet;
        m21 *= rcpDet;
        m22 *= rcpDet;
        m23 *= rcpDet;
    }
    ILINE Matrix34_tpl<F> GetInverted() const
    {
        Matrix34_tpl<F> dst = *this;
        dst.Invert();
        return dst;
    }

    /*!
    *  Name:             ReflectMat34
    *  Description:      reflect a rotation matrix with respect to a plane.
    *
    *  Example:
    *       Vec3 normal( 0.0f,-1.0f, 0.0f);
    *       Vec3 pos(0,1000,0);
    *       Matrix34 m34=CreateReflectionMat( pos, normal );
    */
    ILINE static Matrix34_tpl<F> CreateReflectionMat (const Vec3_tpl<F>& p, const Vec3_tpl<F>& n)
    {
        Matrix34_tpl<F> m;
        F vxy   = -2.0f * n.x * n.y;
        F vxz   = -2.0f * n.x * n.z;
        F vyz   = -2.0f * n.y * n.z;
        F pdotn = 2.0f * (p | n);
        m.m00 = 1.0f - 2.0f * n.x * n.x;
        m.m01 = vxy;
        m.m02 = vxz;
        m.m03 = pdotn * n.x;
        m.m10 = vxy;
        m.m11 = 1.0f - 2.0f * n.y * n.y;
        m.m12 = vyz;
        m.m13 = pdotn * n.y;
        m.m20 = vxz;
        m.m21 = vyz;
        m.m22 = 1.0f - 2.0f * n.z * n.z;
        m.m23 = pdotn * n.z;
        return m;
    }

    AUTO_STRUCT_INFO
};

///////////////////////////////////////////////////////////////////////////////
// Typedefs                                                                  //
///////////////////////////////////////////////////////////////////////////////

typedef Matrix34_tpl<f32>  Matrix34; //always 32 bit
typedef Matrix34_tpl<f64>  Matrix34d;//always 64 bit
typedef Matrix34_tpl<real> Matrix34r;//variable float precision. depending on the target system it can be between 32, 64 or bit
#if AZ_COMPILER_MSVC
    typedef __declspec(align(16)) Matrix34_tpl<f32> Matrix34A;
#elif AZ_COMPILER_CLANG
    typedef Matrix34_tpl<f32> __attribute__((aligned(16))) Matrix34A;
#endif

//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//-------------       implementation of Matrix34      ------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------
//----------------------------------------------------------------------------------

//! multiply all matrix's values by f and return the matrix
template<class F>
ILINE Matrix34_tpl<F> operator * (const Matrix34_tpl<F>& m, const f32 f)
{
    assert(m.IsValid());
    Matrix34_tpl<F> r;
    r.m00 = m.m00 * f;
    r.m01 = m.m01 * f;
    r.m02 = m.m02 * f;
    r.m03 = m.m03 * f;
    r.m10 = m.m10 * f;
    r.m11 = m.m11 * f;
    r.m12 = m.m12 * f;
    r.m13 = m.m13 * f;
    r.m20 = m.m20 * f;
    r.m21 = m.m21 * f;
    r.m22 = m.m22 * f;
    r.m23 = m.m23 * f;
    return r;
}

/*!
*  multiplication of Matrix34 by a (column) Vec3.
*  This function transforms the given input Vec3
*  into the coordinate system defined by this matrix.
*
*  Example:
*   Matrix34 m34;
*   Vec3 vector(44,55,66);
*   Vec3 result = m34*vector;
*/
template<class F>
ILINE Vec3_tpl<F> operator * (const Matrix34_tpl<F>& m, const Vec3_tpl<F>& p)
{
    assert(m.IsValid());
    assert(p.IsValid());
    Vec3_tpl<F> tp;
    tp.x    =   m.m00 * p.x + m.m01 * p.y + m.m02 * p.z + m.m03;
    tp.y    =   m.m10 * p.x + m.m11 * p.y + m.m12 * p.z + m.m13;
    tp.z    =   m.m20 * p.x + m.m21 * p.y + m.m22 * p.z + m.m23;
    return tp;
}


template<class F1, class F2>
ILINE Matrix34_tpl<F1> operator*(const Matrix34_tpl<F1>& l, const Diag33_tpl<F2>& r)
{
    assert(l.IsValid());
    assert(r.IsValid());
    Matrix34_tpl<F1> m;
    m.m00 = l.m00 * r.x;
    m.m01 = l.m01 * r.y;
    m.m02 = l.m02 * r.z;
    m.m03 = l.m03;
    m.m10 = l.m10 * r.x;
    m.m11 = l.m11 * r.y;
    m.m12 = l.m12 * r.z;
    m.m13 = l.m13;
    m.m20 = l.m20 * r.x;
    m.m21 = l.m21 * r.y;
    m.m22 = l.m22 * r.z;
    m.m23 = l.m23;
    return m;
}
template<class F1, class F2>
ILINE Matrix34_tpl<F1>& operator *= (Matrix34_tpl<F1>& l, const Diag33_tpl<F2>& r)
{
    assert(l.IsValid());
    assert(r.IsValid());
    l.m00 *= r.x;
    l.m01 *= r.y;
    l.m02 *= r.z;
    l.m10 *= r.x;
    l.m11 *= r.y;
    l.m12 *= r.z;
    l.m20 *= r.x;
    l.m21 *= r.y;
    l.m22 *= r.z;
    return l;
}
template<class F1, class F2>
ILINE Matrix34_tpl<F1> operator + (const Matrix34_tpl<F1>& l, const Matrix34_tpl<F2>& r)
{
    assert(l.IsValid());
    assert(r.IsValid());
    Matrix34_tpl<F1> m;
    m.m00 = l.m00 + r.m00;
    m.m01 = l.m01 + r.m01;
    m.m02 = l.m02 + r.m02;
    m.m03 = l.m03 + r.m03;
    m.m10 = l.m10 + r.m10;
    m.m11 = l.m11 + r.m11;
    m.m12 = l.m12 + r.m12;
    m.m13 = l.m13 + r.m13;
    m.m20 = l.m20 + r.m20;
    m.m21 = l.m21 + r.m21;
    m.m22 = l.m22 + r.m22;
    m.m23 = l.m23 + r.m23;
    return m;
}
template<class F1, class F2>
ILINE Matrix34_tpl<F1>& operator += (Matrix34_tpl<F1>& l, const Matrix34_tpl<F2>& r)
{
    assert(l.IsValid());
    assert(r.IsValid());
    l.m00 += r.m00;
    l.m01 += r.m01;
    l.m02 += r.m02;
    l.m03 += r.m03;
    l.m10 += r.m10;
    l.m11 += r.m11;
    l.m12 += r.m12;
    l.m13 += r.m13;
    l.m20 += r.m20;
    l.m21 += r.m21;
    l.m22 += r.m22;
    l.m23 += r.m23;
    return l;
}

/*!
*  Implements the multiplication operator: Matrix34=Matrix34*Matrix33
*
*  Matrix33 and Matrix44 are specified in collumn order for a right-handed coordinate-system.
*  AxB = operation B followed by operation A.
*  A multiplication takes 27 muls and 24 adds.
*
*  Example:
*   Matrix34 m34=Matrix33::CreateRotationX(1.94192f);;
*   Matrix33 m33=Matrix34::CreateRotationZ(3.14192f);
*     Matrix34 result=m34*m33;
*/
template<class F>
ILINE Matrix34_tpl<F> operator * (const Matrix34_tpl<F>& l, const Matrix33_tpl<F>& r)
{
    assert(l.IsValid());
    assert(r.IsValid());
    Matrix34_tpl<F> m;
    m.m00 = l.m00 * r.m00 + l.m01 * r.m10 + l.m02 * r.m20;
    m.m10 = l.m10 * r.m00 + l.m11 * r.m10 + l.m12 * r.m20;
    m.m20 = l.m20 * r.m00 + l.m21 * r.m10 + l.m22 * r.m20;
    m.m01 = l.m00 * r.m01 + l.m01 * r.m11 + l.m02 * r.m21;
    m.m11 = l.m10 * r.m01 + l.m11 * r.m11 + l.m12 * r.m21;
    m.m21 = l.m20 * r.m01 + l.m21 * r.m11 + l.m22 * r.m21;
    m.m02 = l.m00 * r.m02 + l.m01 * r.m12 + l.m02 * r.m22;
    m.m12 = l.m10 * r.m02 + l.m11 * r.m12 + l.m12 * r.m22;
    m.m22 = l.m20 * r.m02 + l.m21 * r.m12 + l.m22 * r.m22;
    m.m03 = l.m03;
    m.m13 = l.m13;
    m.m23 = l.m23;
    return m;
}



/*!
*  Implements the multiplication operator: Matrix34=Matrix34*Matrix34
*
*  Matrix34 is specified in collumn order.
*  AxB = rotation B followed by rotation A.
*  This operation takes 36 mults and 27 adds.
*
*  Example:
*   Matrix34 m34=Matrix34::CreateRotationX(1.94192f, Vec3(11,22,33));;
*   Matrix34 m34=Matrix33::CreateRotationZ(3.14192f);
*     Matrix34 result=m34*m34;
*/
template<class F>
ILINE Matrix34_tpl<F> operator * (const Matrix34_tpl<F>& l, const Matrix34_tpl<F>& r)
{
    assert(l.IsValid());
    assert(r.IsValid());
    Matrix34_tpl<F> m;
    m.m00 = l.m00 * r.m00 + l.m01 * r.m10 + l.m02 * r.m20;
    m.m10 = l.m10 * r.m00 + l.m11 * r.m10 + l.m12 * r.m20;
    m.m20 = l.m20 * r.m00 + l.m21 * r.m10 + l.m22 * r.m20;
    m.m01 = l.m00 * r.m01 + l.m01 * r.m11 + l.m02 * r.m21;
    m.m11 = l.m10 * r.m01 + l.m11 * r.m11 + l.m12 * r.m21;
    m.m21 = l.m20 * r.m01 + l.m21 * r.m11 + l.m22 * r.m21;
    m.m02 = l.m00 * r.m02 + l.m01 * r.m12 + l.m02 * r.m22;
    m.m12 = l.m10 * r.m02 + l.m11 * r.m12 + l.m12 * r.m22;
    m.m22 = l.m20 * r.m02 + l.m21 * r.m12 + l.m22 * r.m22;
    m.m03 = l.m00 * r.m03 + l.m01 * r.m13 + l.m02 * r.m23 + l.m03;
    m.m13 = l.m10 * r.m03 + l.m11 * r.m13 + l.m12 * r.m23 + l.m13;
    m.m23 = l.m20 * r.m03 + l.m21 * r.m13 + l.m22 * r.m23 + l.m23;
    return m;
}

/*!
*  Implements the multiplication operator: Matrix44=Matrix34*Matrix44
*
*  Matrix44 and Matrix34 are specified in collumn order.
*    AxB = rotation B followed by rotation A.
*  This operation takes 48 mults and 36 adds.
*
*  Example:
*   Matrix34 m34=Matrix33::CreateRotationX(1.94192f);;
*   Matrix44 m44=Matrix33::CreateRotationZ(3.14192f);
*     Matrix44 result=m34*m44;
*/
template<class F>
ILINE Matrix44_tpl<F> operator * (const Matrix34_tpl<F>& l, const Matrix44_tpl<F>& r)
{
    assert(l.IsValid());
    assert(r.IsValid());
    Matrix44_tpl<F> m;
    m.m00 = l.m00 * r.m00 + l.m01 * r.m10 + l.m02 * r.m20 + l.m03 * r.m30;
    m.m10 = l.m10 * r.m00 + l.m11 * r.m10 + l.m12 * r.m20 + l.m13 * r.m30;
    m.m20 = l.m20 * r.m00 + l.m21 * r.m10 + l.m22 * r.m20 + l.m23 * r.m30;
    m.m30 = r.m30;
    m.m01 = l.m00 * r.m01 + l.m01 * r.m11 + l.m02 * r.m21 + l.m03 * r.m31;
    m.m11 = l.m10 * r.m01 + l.m11 * r.m11 + l.m12 * r.m21 + l.m13 * r.m31;
    m.m21 = l.m20 * r.m01 + l.m21 * r.m11 + l.m22 * r.m21 + l.m23 * r.m31;
    m.m31 = r.m31;
    m.m02 = l.m00 * r.m02 + l.m01 * r.m12 + l.m02 * r.m22 + l.m03 * r.m32;
    m.m12 = l.m10 * r.m02 + l.m11 * r.m12 + l.m12 * r.m22 + l.m13 * r.m32;
    m.m22 = l.m20 * r.m02 + l.m21 * r.m12 + l.m22 * r.m22 + l.m23 * r.m32;
    m.m32 = r.m32;
    m.m03 = l.m00 * r.m03 + l.m01 * r.m13 + l.m02 * r.m23 + l.m03 * r.m33;
    m.m13 = l.m10 * r.m03 + l.m11 * r.m13 + l.m12 * r.m23 + l.m13 * r.m33;
    m.m23 = l.m20 * r.m03 + l.m21 * r.m13 + l.m22 * r.m23 + l.m23 * r.m33;
    m.m33 = r.m33;
    return m;
}

#endif // CRYINCLUDE_CRYCOMMON_CRY_MATRIX34_H

