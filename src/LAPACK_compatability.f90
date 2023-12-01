subroutine slanhe_stackreturn(r, Norm, UpLo, n, A, ldA, work) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    character(C_CHAR) Norm, UpLo
    integer(C_INT) n, ldA
    real(C_FLOAT) A(*), work(*), r, slanhe
    external slanhe
    r = slanhe(Norm, UpLo, n, A, ldA, work)
end subroutine

subroutine dlanhe_stackreturn(r, Norm, UpLo, n, A, ldA, work) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    character(C_CHAR) Norm, UpLo
    integer(C_INT) n, ldA
    real(C_DOUBLE) A(*), work(*), r, dlanhe
    external dlanhe
    r = dlanhe(Norm, UpLo, n, A, ldA, work)
end subroutine

subroutine clanhe_stackreturn(r, Norm, UpLo, n, A, ldA, work) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    character(C_CHAR) Norm, UpLo
    integer(C_INT) n, ldA
    complex(C_FLOAT_COMPLEX) A(*)
    real(C_FLOAT) work(*), r, clanhe
    external clanhe
    r = clanhe(Norm, UpLo, n, A, ldA, work)
end subroutine

subroutine zlanhe_stackreturn(r, Norm, UpLo, n, A, ldA, work) bind(C)
    use, intrinsic:: iso_c_binding
    implicit none
    character(C_CHAR) Norm, UpLo
    integer(C_INT) n, ldA
    complex(C_DOUBLE_COMPLEX) A(*)
    real(C_DOUBLE) work(*), r, zlanhe
    external zlanhe
    r = zlanhe(Norm, UpLo, n, A, ldA, work)
end subroutine
