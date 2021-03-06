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
where INTAKE_CONDITION != 'Aged'
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

SELECT TO_CHAR(DATETIME,'HH24') AS HOUR, COUNT(*) AS COUNT
FROM ANIMAL_OUTS
GROUP BY TO_CHAR(DATETIME,'HH24')
HAVING TO_CHAR(DATETIME,'HH24')>=9 AND TO_CHAR(DATETIME,'HH24')<=19
ORDER BY TO_CHAR(DATETIME,'HH24');


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



SELECT AO.ANIMAL_ID, AO.NAME
FROM ANIMAL_INS AI, ANIMAL_OUTS AO
WHERE AI.ANIMAL_ID(+) = AO.ANIMAL_ID
      AND AI.ANIMAL_ID IS NULL
ORDER BY ANIMAL_ID;



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

SELECT AI.ANIMAL_ID, AI.NAME
FROM ANIMAL_INS AI, ANIMAL_OUTS AO
WHERE AI.ANIMAL_ID = AO.ANIMAL_ID
      AND AI.DATETIME > AO.DATETIME
ORDER BY AI.DATETIME

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


--4. 보호소에서 중성화한 동물
select ANIMAL_ID, ANIMAL_TYPE, NAME
from (select ins.ANIMAL_ID, ins.ANIMAL_TYPE, ins.NAME
      from ANIMAL_INS ins,
           ANIMAL_OUTS outs
      where ins.ANIMAL_ID = outs.ANIMAL_ID and
            ins.SEX_UPON_INTAKE <> outs.SEX_UPON_OUTCOME )
order by ANIMAL_ID;


-------------------String, Date-------------------

--1. 루시와 엘라 찾기
select ANIMAL_ID, NAME, SEX_UPON_INTAKE
from ANIMAL_INS
where NAME in ('Lucy','Ella','Pickle','Rogan','Sabrina','Mitty')
order by ANIMAL_ID;

--2. 이름에 el이 들어가는 동물 찾기
select ANIMAL_ID, NAME
from ANIMAL_INS
where ( NAME like '%el%' or
      NAME like '%eL%' or
      NAME like '%EL%' or
      NAME like '%El%' )
      and ANIMAL_TYPE = 'Dog'
order by NAME;

--NAME을 전부 대문자로 바꾸고 EL이 들어있는지 확인
select ANIMAL_ID, NAME
from ANIMAL_INS
where upper(NAME) like '%EL%'
      and ANIMAL_TYPE = 'Dog'
order by NAME;

--3. 중성화 여부 파악하기
--case when .. then : 가져온 값에 어떤 조건을 걸어 보여주거나 또는 값을 변환할 필요가 있을 경우
select ANIMAL_ID, NAME, 
    case when SEX_UPON_INTAKE like '%Neutered%' then 'O'
         when SEX_UPON_INTAKE like '%Spayed%' then 'O'
    else 'X'
    end
    as 중성화
from ANIMAL_INS
order by ANIMAL_ID;


--4. 오랜 기간 보호한 동물(2)
select ANIMAL_ID, NAME
from (select ins.ANIMAL_ID, ins.NAME, (outs.DATETIME-ins.DATETIME) TIME
      from ANIMAL_INS ins,
           ANIMAL_OUTS outs
      where ins.ANIMAL_ID = outs.ANIMAL_ID
      order by TIME DESC)
where rownum<=2;


--5. DATETIME에서 DATE로 형 변환
select ANIMAL_ID, NAME, to_char(DATETIME,'YYYY-MM-DD') 날짜
from ANIMAL_INS
order by ANIMAL_ID;