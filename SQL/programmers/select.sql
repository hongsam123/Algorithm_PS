-------------------SELECT-------------------

--1.모든 레코드 조회하기
select * from ANIMAL_INS
order by ANIMAL_ID;

--2. 역순 정렬하기
select NAME, DATETIME from ANIMAL_INS
order by ANIMAL_ID desc;

--3. 아픈 동물 찾기
select ANIMAL_ID, NAME from ANIMAL_INS
where INTAKE_CONDITION = "Sick";

--4. 어린 동물 찾기
select ANIMAL_ID, NAME from ANIMAL_INS
where INTAKE_CONDITION <> 'Aged'
order by ANIMAL_ID;

--5. 동물의 아이디와 이름
select ANIMAL_ID, NAME from ANIMAL_INS
order by ANIMAL_ID;

--6. 여러 기준으로 정렬하기
select ANIMAL_ID, NAME, DATETIME from ANIMAL_INS
order by NAME, DATETIME desc;

--7. 상위 n개 레코드
select NAME from ANIMAL_INS
order by DATETIME
limit 1;

-------------------SUM, MAX, MIN-------------------

--1. 최댓값 구하기
select DATETIME from ANIMAL_INS
order by DATETIME desc
limit 1;

--2. 최솟값 구하기
select DATETIME as '시간'
from ANIMAL_INS
order by DATETIME limit 1;

--3. 동물 수 구하기
select count(*) as 'count'
from ANIMAL_INS;

--4. 중복 제거하기
select count(distinct NAME) as 'count'
from ANIMAL_INS;

-------------------GROUP BY-------------------

--1. 고양이와 개는 몇 마리 있을까
select ANIMAL_TYPE, count(*) as count 
from ANIMAL_INS
group by ANIMAL_TYPE
order by ANIMAL_TYPE;

--2. 동명 동물 수 찾기
select NAME, count(*) as COUNT
from ANIMAL_INS
group by NAME
having count(NAME)>=2
order by NAME;  
--COUNT함수는 NULL값을 제외하지만 어느 COLUMN의 NULL값을 제외해야하는지는 QUERY에서 알려줘야 함
--NAME에서 NULL값을 제외하라고 문제에서 명시하였음으로 COUNT(NAME)으로 진행하면 따로 처리를 하지 않아도 된다

--3. 입양 시각 구하기(1)
select HOUR(DATETIME) as HOUR, count(*) as COUNT
from ANIMAL_OUTS
group by HOUR(DATETIME)
having HOUR>=9 and HOUR<=19
order by HOUR(DATETIME);

--4. 입양 시각 구하기(2)
--(4-1) set변수 사용
set @hour = -1;

select (@hour = @hour+1) as HOUR,
(select count(*) from ANIMAL_OUTS where HOUR(DATETIME) = @hour) as COUNT
from ANIMAL_OUTS
where @hour<23;

--사용자 정의 변수인 set 변수는 어떤 변수에 특정값을 할당
--set으로 hour라는 변수를 선언하고 +1씩 하면서 0~23까지 모든 시간에 대한 count 출력

--사용자 정의 변수 선언 및 초기화
set @var = 5;   --"=" MySQL의 대입 연산자, 비교 연산자로 사용된다
set @var := 5;  --SET을 제외한 다른 쿼리문(SELECT 등 )은 "="를 비교 연산자로 인식
                --SET이 아닌 쿼리문에서는 반드시 대입 연산자(":=")를 사용한다

-------------------IS NULL-------------------

--1. 이름이 없는 동물의 아이디
select ANIMAL_ID
from ANIMAL_INS
where NAME is null;

--2. 이름이 있는 동물의 아이디
select ANIMAL_ID
from ANIMAL_INS
where NAME is not null;

--3. NULL처리하기(ORACLE)
select ANIMAL_TYPE, NVL(NAME,'No name') as NAME, SEX_UPON_INTAKE
from ANIMAL_INS
order by ANIMAL_ID;

-------------------JOIN-------------------

--1. 없어진 기록 찾기
--OUTER JOIN => 데이터가 없을 수도 있는 쪽 JOIN컬럼에 (+)를 추가한다
--              데이터가 없더라도 나머지 조인에 의한 결과행은 보여지도록 한다
select ANIMAL_ID, NAME
from (
    select O.ANIMAL_ID,O.NAME,I.INTAKE_CONDITION
    from ANIMAL_INS I,
         ANIMAL_OUTS O
    where I.ANIMAL_ID(+) = O.ANIMAL_ID
)
where INTAKE_CONDITION is null
order by ANIMAL_ID;

--2. 있었는데요 없었습니다
select ANIMAL_ID,NAME
from(
    select I.ANIMAL_ID, I.NAME, I.DATETIME AS I_DATETIME, O.DATETIME AS O_DATETIME
    from ANIMAL_INS I,
         ANIMAL_OUTS O
    where I.ANIMAL_ID = O.ANIMAL_ID
)
where O_DATETIME<I_DATETIME
order by I_DATETIME;


--3. 오랜 기간 보호한 동물(1)
--ROWNUM : select 로 조회된 결과에 순서대로 순번을 매긴다
--         order by를 사용하면 순번이 뒤섞이므로 정렬된 서브 쿼리 결과에 rownum을 매겨야 함
select NAME, DATETIME
from (
    select I.NAME, I.DATETIME
    from ANIMAL_INS I,
         ANIMAL_OUTS O
    where I.ANIMAL_ID = O.ANIMAL_ID(+)
          and O.ANIMAL_ID is null
    order by DATETIME
)
where rownum<=3;